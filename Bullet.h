#pragma once
#include "GameObject.h"
#include "CSprite.h"

class Bullet : public GameObject
{
public:
	explicit Bullet(BaseScene* scene) : GameObject(scene) {}
	virtual ~Bullet() override = default;
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(float deltaTime) override;
	void Dispose() override;
	void OnCollide(GameObject* obj) override;
private:
	void CreateSprite();
	void InitCollision();
	void UpdateCollision();
	CSprite m_sprite = {};
	const float MAX_LIFETIME = 2.0f;
	float m_lifeTime = 0.0f;
};