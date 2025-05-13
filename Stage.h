#pragma once
#include "GameObject.h"
//#include "Player.h"
//#include "Enemy01.h"
#include <vector>

class Player;//前方宣言〇
class Enemy01;//前方宣言

class Stage :
    public GameObject
{
private:
    Player* player_;//ﾌﾟﾚｲﾔｰオブジェクト
    std::vector<Enemy01 *> enemy01_;//敵オブジェクト
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

