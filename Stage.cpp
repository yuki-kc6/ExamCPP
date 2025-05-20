#include "Stage.h"
#include "Player.h"
#include "Enemy01.h"

namespace
{
	const int ENEMY_NUM = 10*7;//敵の数
	const int ENEMY_COL_SIZE = 10;//敵の列数
	const int ENEMY_ROW_SIZE =7;//敵の行数
}

Stage::Stage()
	:GameObject(), player_(nullptr)
{
	AddGameObject(this);//ステージオブジェクトをゲームオブジェクト
	player_ = new Player();
	enemy01_ = std::vector<Enemy01*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = {BOSS,KNIGHT,ZAKO,ZAKO,ZAKO };
		
		enemy01_[i] = new Enemy01(i, enemyType[row]);

		enemy01_[i]->SetPos(col * 55,row * 50);
	}
	
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update();//ﾌﾟﾚｲﾔｰの更新
	for (auto& elm : enemy01_)
	{
		elm->Update();//敵の更新
	}
}

void Stage::Draw()
{
	player_->Draw();//ﾌﾟﾚｲﾔｰの描画
	for (auto& elm : enemy01_)
	{
		elm->Draw();//敵の描画
	}


}
