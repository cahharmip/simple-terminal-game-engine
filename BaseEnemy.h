#pragma once
#include "GameObject.h"
#include "CSprite.h"

class BaseEnemy : public GameObject
{
public:
	~BaseEnemy() = default;
protected:
	CSprite m_sprite;
};