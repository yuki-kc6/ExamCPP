#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
    int hImage_;//ﾌﾟﾚｲﾔｰ画像ハンドル
    float x_, y_;//ﾌﾟﾚｲﾔｰの座標
    float speed_;//ﾌﾟﾚｲﾔｰの移動速度
public:
    Player();
    ~Player();
    void Update()override;
    void Draw()override;
};

