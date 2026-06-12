#pragma once
#include "pch.h"
#include "BaseScene.h"


class CharacterSelectScene : public BaseScene
{
public:
	~CharacterSelectScene() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
	void Dispose() override;

private:
	
};