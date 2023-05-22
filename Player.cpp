#include"Player.h"
#include <cassert>
#include"ImGuiManager.h"

void Player::Initialize(Model* model, uint32_t textureHandle) 
{ 
	assert(model);
	model_=model;
	textureHandle_ = textureHandle;
	worldtransform_.Initialize();
	input_ = Input::GetInstance();
}

void Player::Update() 
{ 
	worldtransform_.TransferMatrix();
	Vector3 move = {0,0,0};

	const float kCharacterSpeed = 0.2f;

	if (input_->PushKey(DIK_LEFT)) 
	{
		move.x -= kCharacterSpeed;

	} else if (input_->PushKey(DIK_RIGHT))
	{
		move.x += kCharacterSpeed;
	}
	 else if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;

	} else if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}
	
	const float kMoveLimitX = 30.0f;
	const float kMoveLimitY = 18.0f;
	
	worldtransform_.translation_.x = max(worldtransform_.translation_.x, -kMoveLimitX);
	worldtransform_.translation_.x = min(worldtransform_.translation_.x, +kMoveLimitX);
	worldtransform_.translation_.y = max(worldtransform_.translation_.y, -kMoveLimitY);
	worldtransform_.translation_.y = min(worldtransform_.translation_.y, +kMoveLimitY);

	worldtransform_.translation_.x += move.x;
	worldtransform_.translation_.y += move.y;
	worldtransform_.translation_.z += move.z;




	worldtransform_.matWorld_ = MakeAffineMatrix(
	    worldtransform_.scale_, worldtransform_.rotation_, worldtransform_.translation_);
	worldtransform_.TransferMatrix();

	// ImGui
	ImGui::Begin("player");
	float sliderValue[3] = {
	    worldtransform_.translation_.x, worldtransform_.translation_.y, worldtransform_.translation_.z};
	ImGui::SliderFloat3("position", sliderValue, 20.0f, 20.0f);
	worldtransform_.translation_ = {sliderValue[0], sliderValue[1], sliderValue[2]};
	ImGui::End();

}
void Player::Draw(ViewProjection viewProjection_) 
{ 
	model_->Draw(worldtransform_,viewProjection_,textureHandle_); 

}