#pragma once
class GameObject
{
public:
	GameObject();
	virtual	~GameObject();
	virtual void Update() = 0;//=0�ŕK���p�����Ȃ��Ǝg���Ȃ��B�݌v�v�z�B
	virtual void Draw() = 0;
};

