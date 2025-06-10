#include "global.h"
#include "Bullet.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;//弾の画像の幅
	const int BULLET_IMAGE_HEIGHT = 33;//画像の高さ
	const float BULLET_INIT_SPEED = 200.0f;//初期移動速度
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue031.png";//弾の画像パス
}

Bullet::Bullet()
	:GameObject(),hImage_(-1),
	x_(-1),y_(-1),speed_(0),isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//読み込み
	speed_ = BULLET_INIT_SPEED;//移動速度
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0), isFired_(false),
	imageSize_({BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//読み込み
	speed_ = BULLET_INIT_SPEED;//移動速度
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != 1) {
		DeleteGraph(hImage_);//画像の解放
	}
	hImage_ = -1;//画像ハンドル無効化
}

void Bullet::Update()
{
	float dt = GetDeltaTime();//弾の移動
	y_ = y_ - speed_ * dt;
	if (y_ < 0) {
		isFired_ = false;//画面外に出たら準備状態に戻す
	}
}

void Bullet::Draw()
{
	//発射されていたら描画
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hImage_,true);//弾の描画
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
