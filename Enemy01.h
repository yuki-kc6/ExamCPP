#pragma once
#include "GameObject.h"

class Enemy01 :
    public GameObject
{
    int hImage_;//�摜�n���h��
    float x_, y_;//���W
    float speed_;//�ړ����x
    bool isAlive;//�G�̐���
public:
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
};
