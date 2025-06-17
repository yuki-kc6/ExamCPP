#include "Enemy01.h"
#include "DxLib.h"
#include "global.h"
#include <string>
#include "Effect.h"
#include "EnemyBeam.h"

namespace
{

	const int ENEMY_IMAGE_WIDTH = 48;//�摜�̕�
	const int ENEMY_IMAGE_HEIGHT = 48;//�摜�̍���
	
	const int ENEMY_INIT_X = 100;//�G�̏���X
	const int ENEMY_INIT_Y = 100;//�G�̏���Y
	const float ENEMY_INIT_SPEED = 100.0f;
	const int ENEMY_BEAM_NUM = 2;//�G��̂����˂ł���e�̐�
	const float BEAM_INTERVAL = 1.0f;//�e�̔��ˊԊu
}

Enemy01::Enemy01()
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	imageSize_({ ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	for (int i = 0; i < ENEMY_BEAM_NUM; i++)
	{
		beam_.push_back(new EnemyBeam(-100, -100));
	}
	//id��type���w�肳��Ȃ��������̏���
}

Enemy01::Enemy01(int id,ETYPE type)
	:GameObject(), 
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	ID_(id),type_(type),
	imageSize_({ ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT })

	//ETYPE::ZAKO=>"Assets\\tiny_ship10.png"
	//ETYPE::MID=>"Assets\\tiny_ship18.png"
	//ETYPE::KNGIHT=>"Assets\\tiny_ship16.png"
	//ETYPE::BOSS=>"Assets\\tiny_ship9.png"
{	
	std::string imagePath[MAX_ETYPE] = {
		"Assets\\tiny_ship10.png",//ZAKO
		"Assets\\tiny_ship18.png",//MID
		"Assets\\tiny_ship16.png",//KNIGHT
		"Assets\\tiny_ship9.png"//BOSS
	};

	moveTime_ = 0.0f;
	hImage_ = LoadGraph(imagePath[type_].c_str());//�G�̉摜��ǂݍ���
	if (hImage_ == -1) {

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	for (int i = 0; i < ENEMY_BEAM_NUM; i++)
	{
		beam_.push_back(new EnemyBeam(-100, -100));
	}

	AddGameObject(this);//�G�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�ɒǉ�
}


Enemy01::~Enemy01()
{
	new Effect({ x_, y_ });

	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�������
	}
	
}

void Enemy01::Update()
{

	float period = 10.0f;//1�����ɂ����鎞�ԁi�b�j
	float omega = 2.0f * 3.14159265f / period;//�p���x ��=2��/T
	moveTime_ = moveTime_ + GetDeltaTime();
	x_ = xorigin_ + xMoveMax_ / 2.0 * sinf(omega * moveTime_);
	y_ = y_;

	static float beamTimer = 3.0f;

	if (beamTimer < 0)
	{
		Shoot();
		beamTimer = 3.0f;
	}
	beamTimer -= GetDeltaTime();

}

void Enemy01::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH,
		y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}

void Enemy01::Shoot()
{
	EnemyBeam* bit = GetActiveBeam();
	if (bit != nullptr)
	{
		bit->SetPos(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_HEIGHT);
		bit->SetFired(true);
	}
}

EnemyBeam* Enemy01::GetActiveBeam()
{
	for (auto& itr : beam_)
	{
		if (!itr->IsFired())
		{
			return itr;
		}
	}

	return nullptr;
}
