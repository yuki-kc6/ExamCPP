#pragma once
#include "GameObject.h"
#include "global.h"

class Bullet; //前方宣言

class Player :
    public GameObject
{
    int hImage_;//ﾌﾟﾚｲﾔｰ画像ハンドル
    float x_, y_;//ﾌﾟﾚｲﾔｰの座標
    float speed_;//ﾌﾟﾚｲﾔｰの移動速度
    Point imageSize_;
    std::vector<Bullet *>bullets_;//ﾌﾟﾚｲﾔｰが発射
    Bullet* GetActiveBullet();

public:
    Player();
    ~Player();
    void Update()override;
    void Draw()override;
    void Shoot();//弾を発射する関数
    Rect GetRect()const { return { x_,y_,imageSize_.x,imageSize_.y }; }//プレイヤーの矩形を取得
    std::vector<Bullet*>GetAllBullets()const { return bullets_; }//全ての玉を取得
};

