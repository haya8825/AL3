#include"Player.h"
#include <cassert>


void Player::Initialize(Model* model, uint32_t textureHandle) 
{ 
	assert(model);
	model_=model;
	textureHandle_ = textureHandle;
	worldtransform_.Initialize();

}

void Player::Update() 
{ 
	worldtransform_.TransferMatrix();

}
void Player::Draw(ViewProjection viewProjection_) 
{ 
	model_->Draw(worldtransform_,viewProjection_,textureHandle_); 

}