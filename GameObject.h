#pragma once
#include <vector>

class GameObject
{
protected:
	bool isAlive_;//生きているか
public:
	GameObject();
	virtual	~GameObject();
	virtual void Update() = 0;//=0で必ず継承しないと使えない。設計思想。
	virtual void Draw() = 0;
	bool IsAlive() { return isAlive_; }//ゲームオブジェクトが生きているか
};

extern std::vector<GameObject*> gameObjects;//ゲームオブジェクトのベクター
extern std::vector<GameObject*> newObjects;//ゲームオブジェクトのベクター

inline void AddGameObject(GameObject* obj)
{
	newObjects.push_back(obj);//ゲームオブジェクトをベクターに追加
}
