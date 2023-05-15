#include"Player.h"
#include <cassert>


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
	if (input_->PushKey(DIK_UP)) {
		move.y -= kCharacterSpeed;

	} else if (input_->PushKey(DIK_DOWN)) {
		move.y += kCharacterSpeed;
	}
	worldtransform_.scale_;

	worldtransform_.rotation_.x *= kCharacterSpeed ;
	worldtransform_.rotation_.y *= kCharacterSpeed ;
	worldtransform_.rotation_.z *= kCharacterSpeed ;




	worldtransform_.matWorld_ = MakeAffineMatrix(
	    worldtransform_.scale_, worldtransform_.rotation_, worldtransform_.translation_);
	worldtransform_.TransferMatrix();
}
void Player::Draw(ViewProjection viewProjection_) 
{ 
	model_->Draw(worldtransform_,viewProjection_,textureHandle_); 

}