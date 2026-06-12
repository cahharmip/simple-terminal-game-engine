#pragma once
#include "GameObject.h"
#include "CSprite.h"

class BaseCharacter : public GameObject
{
public:
	~BaseCharacter() override = default;
protected:
	CSprite m_sprite;
};