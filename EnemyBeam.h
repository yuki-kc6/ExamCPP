#pragma once
#include "GameObject.h"
#include "global.h"

class EnemyBeam :
    public GameObject
{
public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetTarget(const Point& pos);
    void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
    void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; }//発射状態を設定
    bool IsFired() const { return isFired_; }//発射状態を取得
    Rect GetRect()const { return {pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }//プレイヤーの矩形を取得
protected:
private:
    int hImage_;//球の画像ハンドル
    Point pos_;//弾の座標
    Point tpos_;//ターゲットの座標
    float speed_;//移動速度
    Point imageSize_;
    //int isize_x, isize_y;//弾の表示サイズ
    bool isFired_;//発射されているかどうか true:発射された false 発射されていない

};

