#include <DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "Enemy01.h"
#include "Bullet.h"
#include "Input.h"

namespace
{
	const int ENEMY_NUM = 10*7;//敵の数
	const int ENEMY_COL_SIZE = 10;//敵の列数
	const int ENEMY_ROW_SIZE =7;//敵の行数
	const float ENEMY_ALIGN_X = 55.0f;//敵を並べる幅
	const float ENEMY_ALIGN_Y = 50.0f;//敵を並べる高さ
	const int ENEMY_LEFT_MARGIN =(WIN_WIDTH-(ENEMY_ALIGN_X*ENEMY_COL_SIZE))/2;
	const int ENEMY_TOP_MARGIN =75;

	bool IntersectRect(const Rect &a ,const Rect &b) 
	{
		/*int wAB = a.width / 2 + b.width / 2;
		int hAB = a.height / 2 + b.height / 2;
		int distABx = abs(a.x - b.x);
		int distABy = abs(a.y - b.y);
		if (wAB > distABx && hAB > distABy)
		{
			return true;
		}
		else
			
		{
			return false;
		}*/

		bool xOverlap = (a.x < b.x + b.width) && (b.x < a.x + a.width);

		bool yOverlap = (a.y < b.y + b.height) && (b.y < a.y + a.height);

		return xOverlap && yOverlap;

	}
}

Stage::Stage()
	:GameObject(), player_(nullptr),hBackGround(-1),eCount(0)
{
	AddGameObject(this);//ステージオブジェクトをゲームオブジェクト
	
	hBackGround = LoadGraph("Assets\\bg.png");
	state = TITLE;
}

Stage::~Stage()
{
}

void Stage::Update()
{
	switch (state)
	{
	case TITLE:
		Stage::UpdateTitle();
		break;
	case PLAY:
		Stage::UpdatePlay();
		break;
	case GAMEOVER:
		Stage::UpdateGameover();
		break;
	case CLEAR:
		Stage::UpdateClear();
		break;
	}
}

void Stage::UpdateTitle()
{
	DrawBox(0, 0, 100, 100, GetColor(255, 255, 255), false);
	if (Input::IsKeepKeyDown(KEY_INPUT_SPACE))
	{
		player_ = new Player();
		state = PLAY;
		enemy01_ = std::vector<Enemy01*>(ENEMY_NUM);
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			int col = i % ENEMY_COL_SIZE;
			int row = i / ENEMY_COL_SIZE;
			ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,ZAKO,ZAKO,ZAKO };
			enemy01_[i] = new Enemy01(i, enemyType[row]);

			enemy01_[i]->SetMaxMoveX(ENEMY_LEFT_MARGIN);

			enemy01_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN, row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN);

			enemy01_[i]->SetXorigin(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN);
		}
	}
}

void Stage::UpdatePlay()
{
	std::vector<Bullet*>bullets = player_->GetAllBullets();
	for (auto& e : enemy01_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive()) {
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					if (b->IsFired())
						b->SetFired(false);
					if (e->IsAlive()) {
						e->SetAlive(false);
						eCount++;
					}

				}
			}
		}
	}

	if (enemy01_.empty())
	{
		state = CLEAR;
	}
}

void Stage::UpdateGameover()
{

}

void Stage::UpdateClear()
{
	DrawBox(0, 0, 100, 100, GetColor(255, 255, 255), false);
}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackGround, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,100);
}
