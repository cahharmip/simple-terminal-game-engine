#pragma once
#include "BaseEnemy.h"

class EnemyMet : public BaseEnemy
{
public:
	EnemyMet(BaseScene* scene) : BaseEnemy(scene) {}
	~EnemyMet() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
private:
	void CreateSprite();
	void InitCollision();
	void UpdateCollision();
};