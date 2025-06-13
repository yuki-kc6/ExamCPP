#pragma once
#include "GameObject.h"
#include "global.h"
#include <vector>
class Effect :
    public GameObject
{
public:
    Effect(Point _pos);
    ~Effect();
    void Update() override;
    void Draw() override;
private:
    std::vector<int>hImage_;
    //int hImage_;
    Point pos_;
    float animTimer_;
    int frame_;
    float frameTimer_;
};



