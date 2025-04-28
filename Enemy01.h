#pragma once
#include "GameObject.h"

class Enemy01 :
    public GameObject
{
    int hImage_;//画像ハンドル
    float x_, y_;//座標
    float speed_;//移動速度
public:
    Enemy01();
    Enemy01();
    void Update()override;
    void Draw()override;
};

