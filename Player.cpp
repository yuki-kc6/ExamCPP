#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"

namespace
{
	
	const float PLAYER_INIT_SPEED = 200.0f;//��ڲ԰�̏������x
	const int PLAYER_IMAGE_WIDTH = 48;//��ڲ԰�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//��ڲ԰�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//��ڲ԰�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT-PLAYER_BASE_MARGIN;//��ڲ԰�̏���Y���W
}




Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//��ڲ԰�̉摜
	if (hImage_ == -1) {
		//�摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		//�G���[��Ԃ��ăQ�[���I��
	}
	x_ = PLAYER_INIT_X;//�������x
	y_ = PLAYER_INIT_Y;//�������x
	speed_ = PLAYER_INIT_SPEED;//�������x

}

Player::~Player()
{
	//�摜�T�C�Y������i���Ə����j
}

void Player::Update()
{
	float dt = GetDeltaTime();
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		x_ -= speed_  *dt;//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		x_ += speed_ * dt;//���Ɉړ�
	}

}

void Player::Draw()
{
	//�v���C���[�̉摜��`��i�摜�̌��_�͍���j
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, 
		hImage_, TRUE);
}
