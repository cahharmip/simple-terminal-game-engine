#pragma once
#include "GameObject.h"
#include "CSprite.h"

class BaseEnemy : public GameObject
{
public:
	explicit BaseEnemy(BaseScene* scene) : GameObject(scene) {}
	~BaseEnemy() = default;
protected:
	CSprite m_sprite;
};