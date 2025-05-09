#include "DxLib.h"
#include "Player.h"
#include "global.h"
#include "Input.h"
#include "Enemy01.h"

namespace
{
	const int BGCOL[3] = { 0,0,0};
	int crrTime;
	int prevTime;

}

float gDeltaTime = 0.0f;//�t���[���Ԃ̎��ԍ�

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOL[0],BGCOL[1],BGCOL[2]);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "�E�B���h�E�̃e�X�g");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();


	Player* player = new Player();
	Enemy01* enemy01 = new Enemy01[10];
	for (int i = 0; i < 10; i++) {
		enemy01[i].SetPos(100 + i * 50, 100);
	}

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();

		crrTime = GetNowCount();//���݂̎��Ԃ��擾
		//�O��̎��ԂƂ̍������v�Z
		float deltaTime = (crrTime - prevTime) / 1000.0f;//�b�P�ʂɕϊ�
		gDeltaTime = deltaTime;//�O���[�o���ϐ��ɕϊ�


		//�����ɂ�肽������������
		player->Update();
		player->Draw();

		for (int i = 0; i < 10; i++)
		{
			(enemy01 + i)->Update();//enemy[i].Update�ƈꏏ
			(enemy01 + i)->Draw();//enemy[i].Draw�ƈꏏ
		}

		//�����܂�


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