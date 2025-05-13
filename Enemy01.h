#pragma once
#include "GameObject.h"


enum ETYPE
{
    ZAKO, MID, KNGIHT, BOSS,MAX_ETYPE
};

class Enemy01 :
    public GameObject
{
    int hImage_;//‰æ‘œƒnƒ“ƒhƒ‹
    float x_, y_;//À•W
    float speed_;//ˆÚ“®‘¬“x
    bool isAlive;//“G‚Ì¶€
    int ID_;//“G‚ÌID
    ETYPE type_;//“G‚Ìí—Ş
public:
    Enemy01(int id,ETYPE type);
    Enemy01();
    ~Enemy01();
    void Update()override;
    void Draw()override;
    void SetPos(float x, float y) { x_ = x; y_ = y; }//“G‚ÌÀ•W‚ğİ’è
    //void SetID(int id) { ID_ = id; }//“G‚ÌID‚ğİ’è
};
