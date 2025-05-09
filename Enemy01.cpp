#include "Enemy01.h"
#include "DxLib.h"
#include "global.h"

namespace
{

	const int ENEMY_IMAGE_WIDTH = 48;//�摜�̕�
	const int ENEMY_IMAGE_HEIGHT = 48;//�摜�̍���
	
	const int ENEMY_INIT_X = 100;//�G�̏���X
	const int ENEMY_INIT_Y = 100;//�G�̏���Y
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
		DeleteGraph(hImage_);//�摜�̃n���h�������
	}
}

void Enemy01::Update()
{

}

void Enemy01::Draw()
{
	DrawExtendGraph(x_, y_, x_+ENEMY_IMAGE_WIDTH,y_+ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
