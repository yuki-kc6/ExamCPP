#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"

namespace
{
	
	const float PLAYER_INTI_SPEED = 200.0f;//ﾌﾟﾚｲﾔｰの初期速度
	const int PLAYER_IMAGE_WIDTH = 48;//ﾌﾟﾚｲﾔｰの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;//ﾌﾟﾚｲﾔｰの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;//プレイヤーの基準マージン

	const float PLAYER_INTI_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//ﾌﾟﾚｲﾔｰの初期X座標
	const float PLAYER_INTI_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT-PLAYER_BASE_MARGIN;//ﾌﾟﾚｲﾔｰの初期Y座標
}




Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//ﾌﾟﾚｲﾔｰの画像
	if (hImage_ == -1) {
		//画像の読み込みに失敗した場合のエラーハンドリング
		//エラーを返してゲーム終了
	}
	x_ = PLAYER_INTI_X;//初期速度
	y_ = PLAYER_INTI_Y;//初期速度
	speed_ = PLAYER_INTI_SPEED;//初期速度

}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		x_ -= speed_  *GetDeltaTime();//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		x_ += speed_ * GetDeltaTime();//左に移動
	}
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
