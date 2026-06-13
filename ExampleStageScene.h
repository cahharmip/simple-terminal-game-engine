#pragma once
#include "pch.h"
#include "BaseScene.h"
#include "X.h"
#include "Zero.h"
#include "EnemyMet.h"

class ExampleStageScene : public BaseScene
{
public:
	~ExampleStageScene() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
	void Dispose() override;
private:
	X player_x;
	EnemyMet e_met;
};