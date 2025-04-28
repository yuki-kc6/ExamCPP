#include "Enemy01.h"
#include "DxLib.h"
#include "global.h"
Enemy01::Enemy01()
	:GameObject(), hImage_(-1), x_(0), y_(0).speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship18");
	if (hImage_ == --1) {

	}
	x_ = 0;
	y_ = 0;
}

void Enemy01::Update()
{
}

void Enemy01::Draw()
{
	DrawExtendGraph(x_, y_, 0,0, hImage_, TRUE);
}
