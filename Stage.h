#pragma once
#include "GameObject.h"
#include <vector>

class Player;//�O���錾�Z
class Enemy01;//�O���錾

class Stage :
    public GameObject
{
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
private:
    Player* player_;//��ڲ԰�I�u�W�F�N�g
    std::vector<Enemy01*> enemy01_;//�G�I�u�W�F�N�g
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

