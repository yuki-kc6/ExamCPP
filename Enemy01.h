#pragma once
#include "GameObject.h"


enum ETYPE
{
    ZAKO, MID, KNGIHT, BOSS,MAX_ETYPE
};

class Enemy01 :
    public GameObject
{
    int hImage_;//�摜�n���h��
    float x_, y_;//���W
    float speed_;//�ړ����x
    bool isAlive;//�G�̐���
    int ID_;//�G��ID
    ETYPE type_;//�G�̎��
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
    //void SetID(int id) { ID_ = id; }//�G��ID��ݒ�
};
