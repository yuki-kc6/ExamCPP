#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
    int hImage_;//��ڲ԰�摜�n���h��
    float x_, y_;//��ڲ԰�̍��W
    float speed_;//��ڲ԰�̈ړ����x
public:
    Player();
    ~Player();
    void Update()override;
    void Draw()override;
};

