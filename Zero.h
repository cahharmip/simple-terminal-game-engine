#pragma once
#include "pch.h"
#include "BaseCharacter.h"
#include "ControlableObject.h"
#include "CSprite.h"
#include <vector>

class Zero : public BaseCharacter, public ControlableObject
{
public:
	~Zero() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
private:
	void CreateSprite();
};