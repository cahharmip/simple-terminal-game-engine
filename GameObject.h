#pragma once
#include "pch.h"
#include <array>

class BaseScene;

struct transform
{
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
};

class GameObject
{
public:
	GameObject() = delete;
	explicit GameObject(BaseScene* scene)
		: m_owner_scene(scene){}
	virtual ~GameObject() = default;
	virtual void Init() {};
	virtual void Update(float deltatime) {};
	virtual void Draw(float deltatime) {};
	virtual void Dispose() {};
	void Destroy() { m_isDestroyed = true; }
	bool IsDestroyed() const { return m_isDestroyed; }
	Rect GetCollision() const { return m_collision; }
	virtual void OnCollide(GameObject* obj) {};
	transform transform = {};

protected:
	BaseScene* m_owner_scene = nullptr;
	bool m_isDestroyed = false;
	Rect m_collision = {};
};
