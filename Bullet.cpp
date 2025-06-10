#include "global.h"
#include "Bullet.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;//�e�̉摜�̕�
	const int BULLET_IMAGE_HEIGHT = 33;//�摜�̍���
	const float BULLET_INIT_SPEED = 200.0f;//�����ړ����x
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue031.png";//�e�̉摜�p�X
}

Bullet::Bullet()
	:GameObject(),hImage_(-1),
	x_(-1),y_(-1),speed_(0),isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//�ǂݍ���
	speed_ = BULLET_INIT_SPEED;//�ړ����x
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0), isFired_(false),
	imageSize_({BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//�ǂݍ���
	speed_ = BULLET_INIT_SPEED;//�ړ����x
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != 1) {
		DeleteGraph(hImage_);//�摜�̉��
	}
	hImage_ = -1;//�摜�n���h��������
}

void Bullet::Update()
{
	float dt = GetDeltaTime();//�e�̈ړ�
	y_ = y_ - speed_ * dt;
	if (y_ < 0) {
		isFired_ = false;//��ʊO�ɏo���珀����Ԃɖ߂�
	}
}

void Bullet::Draw()
{
	//���˂���Ă�����`��
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hImage_,true);//�e�̕`��
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
