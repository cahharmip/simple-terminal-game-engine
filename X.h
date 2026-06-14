#pragma once
#include "pch.h"
#include "BaseCharacter.h"
#include "ControlableObject.h"
#include "CSprite.h"
#include <vector>

class X : public BaseCharacter, public ControlableObject
{
public:
	~X() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
	void OnMoveUp(float deltaTime) override;
	void OnMoveDown(float deltaTime) override;
	void OnMoveLeft(float deltaTime) override;
	void OnMoveRight(float deltaTime) override;
	void OnMoveJump(float deltaTime) override;
	void OnMoveAttack(float deltaTime) override;
	void OnMoveDash(float deltaTime) override;
private:
	void CreateSprite();
	void CheckPropertyStateInput();
	void CheckActionStateInput();
	void CheckMovementStateInput();
	void CheckDirectionStateInput();
	void CheckPositionState();
	void UpdatePosition(float deltatime);
};