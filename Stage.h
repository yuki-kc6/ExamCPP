#pragma once
#include "GameObject.h"
#include <vector>

class Player;//�O���錾�Z
class Enemy01;//�O���錾

class Stage :
    public GameObject
{
private:
    Player* player_;//��ڲ԰�I�u�W�F�N�g
    std::vector<Enemy01 *> enemy01_;//�G�I�u�W�F�N�g
    int hBackGround;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

