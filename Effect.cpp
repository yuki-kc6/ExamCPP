#include "Effect.h"
#include "DxLib.h"
#include<string>

namespace {
	const float ANIM_TIME = { 1.0f };//アニメの総時間
	const int EFFECT_IMAGE_SIZE = 48;//画像サイズ
	const std::string EIMG_PATH = "Assets\\explosion.png";
	const int MAX_FLAME = 9;//画像の分割数
	const int DIV_NUM = 3;//画像の分割数（割り算用）
	const float FRAME_TIME = ANIM_TIME / MAX_FLAME;//1コマの時間の初期値
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
		frame_++;//フレームを１増やす
		frameTimer_ = FRAME_TIME - frameTimer_;//リセット
	}

}

void Effect::Draw()
{
	DrawExtendGraphF(pos_.x, pos_.y, 
		pos_.x + EFFECT_IMAGE_SIZE, pos_.y + EFFECT_IMAGE_SIZE,
		hImage_[frame_],TRUE);
}
