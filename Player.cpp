#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"
#include "Bullet.h"


namespace
{
	
	const float PLAYER_INIT_SPEED = 200.0f;//��ڲ԰�̏������x
	const int PLAYER_IMAGE_WIDTH = 48;//��ڲ԰�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//��ڲ԰�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//��ڲ԰�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT-PLAYER_BASE_MARGIN;//��ڲ԰�̏���Y���W
	const int BULLET_IMAGE_MARGIN = 17; //�e�̐^�񒆂�6.5�B�v���C���[�̐^�񒆂ƍ��킹��B�v���C���[�̉���/2-�e�̕�/2
	const float BULLET_INTERVAL = 0.5f;//�e�̔��ˊԊu
	const int PLAYER_BULLET_NUM = 5;//��ڲ԰�������ɔ��˂ł���e�̐�

}

Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0),imageSize_({PLAYER_IMAGE_WIDTH,PLAYER_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//��ڲ԰�̉摜  
	if (hImage_ == -1) {
		//�摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		//�G���[��Ԃ��ăQ�[���I��
	}
	x_ = PLAYER_INIT_X;//�������x
	y_ = PLAYER_INIT_Y;//�������x
	speed_ = PLAYER_INIT_SPEED;//�������x
	for (int i = 0; i < PLAYER_BULLET_NUM; i++)
	{
		bullets_.push_back(new Bullet(-10,-10)); //�e�̃x�N�^�[��������
	}

	AddGameObject(this);//��ڲ԰�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�ɒǉ�
}

Player::~Player()
{
	//�摜�T�C�Y������i���Ə����j
}

void Player::Update()
{
	Point nextP = {x_,y_};
	float dt = GetDeltaTime();
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		nextP.x =x_- speed_  *dt;//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		nextP.x =x_+ speed_ * dt;//���Ɉړ�
	}

	if (nextP.x >= 0 && (nextP.x+PLAYER_IMAGE_WIDTH) <= WIN_WIDTH)
	{
		x_ = nextP.x;
		y_ = nextP.y;
	}



	static float bulletTimer = 0.0f;
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;//�^�C�}�[������
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
		if (bulletTimer <=0.0f) {
			Shoot();
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);//�e�̔���
			//�v���C���[�̉E�ォ��^�񒆂ɂȂ鉡���𑫂�
			bulletTimer = BULLET_INTERVAL;//�e�̔��ˊԊu�����Z�b�g
		}
	}

}

void Player::Draw()
{
	//�v���C���[�̉摜��`��i�摜�̌��_�͍���j
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, 
		hImage_, TRUE);
}

//�e�����֐�
void Player::Shoot()
{
	//for (auto& itr : bullets_)
	//{
	//	if (itr->IsFired() == false)
	//	{
	//		itr->SetPos(x_ + BULLET_IMAGE_MARGIN, y_);//�e�̈ʒu
	//		itr->SetFired(true);//���ˏ�Ԃɂ���
	//		break;//����˂����烋�[�v�𔲂���
	//	}
	//}

	Bullet* bit = GetActiveBullet();
	if (bit != nullptr)
	{
		bit->SetPos(x_ + BULLET_IMAGE_MARGIN, y_);//�e�̈ʒu��ݒ�
		bit->SetFired(true);//���ˏ�Ԃɂ���
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr;//���˂���Ă��Ȃ��e��Ԃ�
		}
	}
	return nullptr;
}
