#include "Enemy01.h"
#include "DxLib.h"
#include "global.h"

namespace
{

	const int ENEMY_IMAGE_WIDTH = 48;//‰æ‘œ‚Ì•
	const int ENEMY_IMAGE_HEIGHT = 48;//‰æ‘œ‚Ì‚‚³
	
	const int ENEMY_INIT_X = 100;//“G‚Ì‰ŠúX
	const int ENEMY_INIT_Y = 100;//“G‚Ì‰ŠúY
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
}

Enemy01::~Enemy01()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//‰æ‘œ‚Ìƒnƒ“ƒhƒ‹‚ğ‰ğ•ú
	}
}

void Enemy01::Update()
{

}

void Enemy01::Draw()
{
	DrawExtendGraph(x_, y_, x_+ENEMY_IMAGE_WIDTH,y_+ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
