#pragma once


namespace Input {
	//�L�[�{�[�h�擾�֘A
	//�L�[�{�[�h�̏�Ԃ��X�V
	void KeyStateUpdate();
	//�L�[�������ꂽ�u��
	bool IsKeyUP(int keyCode);
	//�L�[�������ꂽ�u�ԁi���������j
	bool IsKeyDown(int keyCode);
	//�L�[��������Ă����
	int IsKeepKeyDown(int keyCode);
}