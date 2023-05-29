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
	    void Initialize(Model* model, const Vector3& position);

		/// <summary>
	    /// 更新
	    /// </summary>
	    void Update();

		void Draw(const ViewProjection& viewProjection);


	private:
	    WorldTransform worldTransform_;
	    Model* model_ = nullptr;
	    uint32_t textureHandle_ = 0u ;
	    Vector3 velocity_;
};