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
    int hImage_;//画像ハンドル
    float x_, y_;//座標
    float speed_;//移動速度
    int ID_;//敵のID
    ETYPE type_;//敵の種類
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//敵の座標を設定
    Rect GetRect()const { return { x_,y_,ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT }; }//プレイヤーの矩形を取得
    //void SetID(int id) { ID_ = id; }//敵のIDを設定
};
