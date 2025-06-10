#pragma once
#include "GameObject.h"
#include <vector>

class Player;//前方宣言〇
class Enemy01;//前方宣言

class Stage :
    public GameObject
{
private:
    Player* player_;//ﾌﾟﾚｲﾔｰオブジェクト
    std::vector<Enemy01 *> enemy01_;//敵オブジェクト
    int hBackGround;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

