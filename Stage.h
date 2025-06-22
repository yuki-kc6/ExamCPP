#pragma once
#include "GameObject.h"
#include <vector>

class Player;//前方宣言〇
class Enemy01;//前方宣言

class Stage :
    public GameObject
{
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
private:
    Player* player_;//ﾌﾟﾚｲﾔｰオブジェクト
    std::vector<Enemy01*> enemy01_;//敵オブジェクト
    int hBackGround;
    int hTitle;
    enum  State
    {
        TITLE = 0,
        PLAY,
        GAMEOVER,
        CLEAR
    };
    State state;
    int eCount;
    void UpdateTitle();
    void UpdatePlay();
    void UpdateGameover();
    void UpdateClear();
    void PlayerVSEnemyBullet();
};

