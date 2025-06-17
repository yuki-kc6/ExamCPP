#pragma once
#include "GameObject.h"
#include "global.h"

enum ETYPE
{
    ZAKO, MID, KNIGHT, BOSS,MAX_ETYPE
};


class EnemyBeam;

class Enemy01 :
    public GameObject
{
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void Shoot();
    void SetPos(float x, float y) { x_ = x; y_ = y; }//�G�̍��W��ݒ�
    Rect GetRect()const { return { x_,y_,imageSize_.x,imageSize_.y }; }//�v���C���[�̋�`���擾
    //void SetID(int id) { ID_ = id; }//�G��ID��ݒ�
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    std::vector<EnemyBeam*>GetAllBeam()const { return beam_; }//�S�Ă̋ʂ��擾
protected:

private:
    int hImage_;//�摜�n���h��
    float x_, y_;//���W
    float speed_;//�ړ����x
    Point imageSize_;
    int ID_;//�G��ID
    ETYPE type_;//�G�̎��
    std::vector<EnemyBeam*>beam_;
    float xMoveMax_;
    float xorigin_;
    float moveTime_;
    EnemyBeam* GetActiveBeam();

};
