#pragma once
class GameObject
{
public:
	GameObject();
	virtual	~GameObject();
	virtual void Update() = 0;//=0で必ず継承しないと使えない。設計思想。
	virtual void Draw() = 0;
};

