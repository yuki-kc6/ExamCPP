#pragma once
#include "GameObject.h"
#include "global.h"

class Bullet; //�O���錾

class Player :
    public GameObject
{
    int hImage_;//��ڲ԰�摜�n���h��
    float x_, y_;//��ڲ԰�̍��W
    float speed_;//��ڲ԰�̈ړ����x
    Point imageSize_;
    std::vector<Bullet *>bullets_;//��ڲ԰������
    Bullet* GetActiveBullet();

public:
    Player();
    ~Player();
    void Update()override;
    void Draw()override;
    void Shoot();//�e�𔭎˂���֐�
    Rect GetRect()const { return { x_,y_,imageSize_.x,imageSize_.y }; }//�v���C���[�̋�`���擾
    std::vector<Bullet*>GetAllBullets()const { return bullets_; }//�S�Ă̋ʂ��擾
};

