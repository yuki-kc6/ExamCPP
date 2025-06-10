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
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//敵の座標を設定
    Rect GetRect()const { return { x_,y_,imageSize_.x,imageSize_.y }; }//プレイヤーの矩形を取得
    //void SetID(int id) { ID_ = id; }//敵のIDを設定
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
protected:

private:
    int hImage_;//画像ハンドル
    float x_, y_;//座標
    float speed_;//移動速度
    Point imageSize_;
    int ID_;//敵のID
    ETYPE type_;//敵の種類
    float xMoveMax_;
    float xorigin_;
    float moveTime_;
};
