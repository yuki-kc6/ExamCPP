#include "Stage.h"
#include "Player.h"
#include "Enemy01.h"

namespace
{
	const int ENEMY_NUM = 10*7;//“G‚Ì”
	const int ENEMY_COL_SIZE = 10;//“G‚Ì—ñ”
	const int ENEMY_ROW_SIZE =7;//“G‚Ìs”
}

Stage::Stage()
	:GameObject(), player_(nullptr)
{
	player_ = new Player();
	enemy01_ = std::vector<Enemy01*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = {BOSS,KNIGHT.ZAKO,ZAKO,ZAKO };
		
		enemy01_[i] = new Enemy01(i, enemyType[row]);

		enemy01_[i]->SetPos(col * 55,row * 50);
	}
	
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update();//ÌßÚ²Ô°‚ÌXV
	for (auto& elm : enemy01_)
	{
		elm->Update();//“G‚ÌXV
	}
}

void Stage::Draw()
{
	player_->Draw();//ÌßÚ²Ô°‚Ì•`‰æ
	for (auto& elm : enemy01_)
	{
		elm->Draw();//“G‚Ì•`‰æ
	}


}
