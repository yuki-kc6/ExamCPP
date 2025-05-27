#pragma once
#include "GameObject.h"
#include "global.h"

enum ETYPE
{
    ZAKO, MID, KNIGHT, BOSS,MAX_ETYPE
};

class Enemy01 :
    public GameObject
{
    int hImage_;//�摜�n���h��
    float x_, y_;//���W
    float speed_;//�ړ����x
    int ID_;//�G��ID
    ETYPE type_;//�G�̎��
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
    Rect GetRect()const { return { x_,y_,ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT }; }//�v���C���[�̋�`���擾
    //void SetID(int id) { ID_ = id; }//�G��ID��ݒ�
};
