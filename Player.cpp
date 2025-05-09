#include "Player.h"
#include "DxLib.h"
#include "global.h"
#include "Input.h"

namespace
{
	
	const float PLAYER_INIT_SPEED = 200.0f;//ﾌﾟﾚｲﾔｰの初期速度
	const int PLAYER_IMAGE_WIDTH = 48;//ﾌﾟﾚｲﾔｰの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;//ﾌﾟﾚｲﾔｰの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;//プレイヤーの基準マージン

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2;//ﾌﾟﾚｲﾔｰの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT-PLAYER_BASE_MARGIN;//ﾌﾟﾚｲﾔｰの初期Y座標
}




Player::Player()
	:GameObject(),hImage_(-1),x_(0),y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//ﾌﾟﾚｲﾔｰの画像
	if (hImage_ == -1) {
		//画像の読み込みに失敗した場合のエラーハンドリング
		//エラーを返してゲーム終了
	}
	x_ = PLAYER_INIT_X;//初期速度
	y_ = PLAYER_INIT_Y;//初期速度
	speed_ = PLAYER_INIT_SPEED;//初期速度

}

Player::~Player()
{
	//画像サイズを解放（あと書く）
}

void Player::Update()
{
	float dt = GetDeltaTime();
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		x_ -= speed_  *dt;//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		x_ += speed_ * dt;//左に移動
	}

}

void Player::Draw()
{
	//プレイヤーの画像を描画（画像の原点は左上）
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, 
		hImage_, TRUE);
}
