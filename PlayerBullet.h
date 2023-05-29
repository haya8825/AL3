#include"Vector3.h"
#include"Model.h"
#include"WorldTransform.h"

#pragma once
/// <summary>
/// 自キャラの弾
/// </summary>
class PlayerBullet {

	public:
	/// <summary>
	/// 初期化
	/// </summary>
	    void Initialize(Model* model, const Vector3& position, const Vector3& velocity);

		/// <summary>
	    /// 更新
	    /// </summary>
	    void Update();

		void Draw(const ViewProjection& viewProjection);

 bool IsDead() const { return isDead_; }
	private:
	    WorldTransform worldTransform_;
	    Model* model_ = nullptr;
	    uint32_t textureHandle_ = 0u ;
	    Vector3 velocity_;
	    static const int32_t kLifeTime = 60 * 5;
	    int32_t deathTimer_ = kLifeTime;

		bool isDead_ = false;
	   
};