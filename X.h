#pragma once
#include "pch.h"
#include "BaseCharacter.h"
#include "ControlableObject.h"
#include "CSprite.h"
#include <vector>

class X : public BaseCharacter, public ControlableObject
{
public:
	explicit X(BaseScene* scene) : GameObject(scene), BaseCharacter(scene), ControlableObject(scene) {}
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
	void CheckPositionState();
	void UpdatePosition(float deltatime);
	void InitCollision();
	void UpdateCollision();
	const float ATTACK_COOLDOWN = 0.2f;
	float m_cooldown_count = 0.0f;
};