#include "Enemy01.h"
#include "DxLib.h"
#include "global.h"
#include <string>

namespace
{

	const int ENEMY_IMAGE_WIDTH = 48;//画像の幅
	const int ENEMY_IMAGE_HEIGHT = 48;//画像の高さ
	
	const int ENEMY_INIT_X = 100;//敵の初期X
	const int ENEMY_INIT_Y = 100;//敵の初期Y
	const int ENEMY_INIT_SPEED = 100.0f;
}

Enemy01::Enemy01()
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	isAlive(true)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	//idとtypeを指定されなかった時の処理
}

Enemy01::Enemy01(int id,ETYPE type)
	:GameObject(), 
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	isAlive(true),
	ID_(id),type_(type)
{
	//ETYPE::ZAKO=>"Assets\\tiny_ship10.png"
	//ETYPE::MID=>"Assets\\tiny_ship18.png"
	//ETYPE::KNGIHT=>"Assets\\tiny_ship16.png"
	//ETYPE::BOSS=>"Assets\\tiny_ship9.png"
	
	std::string imagePath[MAX_ETYPE] = {
		"Assets\\tiny_ship10.png",//ZAKO
		"Assets\\tiny_ship18.png",//MID
		"Assets\\tiny_ship16.png",//KNIGHT
		"Assets\\tiny_ship9.png"//BOSS
	};
	hImage_ = LoadGraph(imagePath[type_].c_str());//敵の画像を読み込む
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	AddGameObject(this);//敵オブジェクトをゲームオブジェクトに追加
}


Enemy01::~Enemy01()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//画像のハンドルを解放
	}
}

void Enemy01::Update()
{

}

void Enemy01::Draw()
{
	DrawExtendGraph(x_, y_, x_+ENEMY_IMAGE_WIDTH,y_+ENEMY_IMAGE_HEIGHT, hImage_, TRUE);

}
