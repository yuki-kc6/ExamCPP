#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
private:
    int hImage_;//球の画像ハンドル
    float x_, y_;//座標
    float speed_;//移動速度
    bool isAlive_;//生きているか
    int isize_x, isize_y;//弾の表示サイズ
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
};

