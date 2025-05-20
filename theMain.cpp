#include "DxLib.h"
#include "global.h"
#include "Input.h"
#include <vector>
#include "Stage.h"
namespace
{
	const int BGCOL[3] = { 0,0,0};
	int crrTime;
	int prevTime;

}

std::vector<GameObject*> gameObjects;//ゲームオブジェクトのベクター
std::vector<GameObject*> newObjects;

float gDeltaTime = 0.0f;//フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOL[0],BGCOL[1],BGCOL[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage();


	//const int ENEMY_NUM = 10;//敵の数

	//Player* player = new Player();
	//Enemy01* enemy01 = new Enemy01[ENEMY_NUM];
	/*for (int i = 0; i < ENEMY_NUM; i++)
		{
			enemy01[i].SetPos(100 + i * 50, 100);
		}*/

	
	/*for (int i = 0; i < 10; i++) {
		enemy01[i].SetPos(100 + i * 50, 100);
	}*/

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();

		crrTime = GetNowCount();//現在の時間を取得
		//前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f;//秒単位に変換
		gDeltaTime = deltaTime;//グローバル変数に変換

		
		//ここにやりたい処理を書く
		//ゲームオブジェクトの追加
		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects) {
				gameObjects.push_back(obj);//新しいゲームオブジェクトを追加
			}
		}
		newObjects.clear();
		//gameObjectの更新
		for (auto& obj : gameObjects)
		{
			obj->Update();
		}
		//gameObjectの描画
		for (auto& obj : gameObjects)
		{
			obj->Draw();
		}
		//ここまで


		ScreenFlip();
		WaitTimer(16);
		prevTime = crrTime;

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}