#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"

namespace
{
	
	const float PLAYER_INTI_SPEED = 200.0f;//��ڲ԰�̏������x
	const int PLAYER_IMAGE_WIDTH = 48;//��ڲ԰�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//��ڲ԰�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��

	const float PLAYER_INTI_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//��ڲ԰�̏���X���W
	const float PLAYER_INTI_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT-PLAYER_BASE_MARGIN;//��ڲ԰�̏���Y���W
}




Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//��ڲ԰�̉摜
	if (hImage_ == -1) {
		//�摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		//�G���[��Ԃ��ăQ�[���I��
	}
	x_ = PLAYER_INTI_X;//�������x
	y_ = PLAYER_INTI_Y;//�������x
	speed_ = PLAYER_INTI_SPEED;//�������x

}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		x_ -= speed_  *GetDeltaTime();//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		x_ += speed_ * GetDeltaTime();//���Ɉړ�
	}
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
