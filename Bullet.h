#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
private:
    int hImage_;//���̉摜�n���h��
    float x_, y_;//���W
    float speed_;//�ړ����x
    bool isAlive_;//�����Ă��邩
    int isize_x, isize_y;//�e�̕\���T�C�Y
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
};

