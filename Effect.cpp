#include "Effect.h"
#include "DxLib.h"
#include<string>

namespace {
	const float ANIM_TIME = { 1.0f };//�A�j���̑�����
	const int EFFECT_IMAGE_SIZE = 48;//�摜�T�C�Y
	const std::string EIMG_PATH = "Assets\\explosion.png";
	const int MAX_FLAME = 9;//�摜�̕�����
	const int DIV_NUM = 3;//�摜�̕������i����Z�p�j
	const float FRAME_TIME = ANIM_TIME / MAX_FLAME;//1�R�}�̎��Ԃ̏����l
}


Effect::Effect(Point _pos)
	:GameObject(),pos_({_pos.x,_pos.y}),
	animTimer_(ANIM_TIME), hImage_(std::vector<int>(MAX_FLAME,-1)),
	frame_(0),frameTimer_(FRAME_TIME)
{ 
	//hImage_ : LoadGraph(EIMG_PATH.c_str());
	LoadDivGraph(EIMG_PATH.c_str(), MAX_FLAME, DIV_NUM, DIV_NUM, 
		EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data());
	AddGameObject(this);
}

Effect::~Effect()
{
	//DeleteGraph(hImage_);
	for (auto& itr : hImage_)
		DeleteGraph(itr);
	hImage_.clear();
}

void Effect::Update()
{
	float dt = GetDeltaTime();

	animTimer_ = animTimer_ - dt;
	if (animTimer_ < 0)
	{
		this->isAlive_ = false;
	}

	frameTimer_ = frameTimer_ - dt;

	if (frameTimer_ < 0)
	{
		frame_++;//�t���[�����P���₷
		frameTimer_ = FRAME_TIME - frameTimer_;//���Z�b�g
	}

}

void Effect::Draw()
{
	DrawExtendGraphF(pos_.x, pos_.y, 
		pos_.x + EFFECT_IMAGE_SIZE, pos_.y + EFFECT_IMAGE_SIZE,
		hImage_[frame_],TRUE);
}
