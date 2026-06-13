#pragma once
#include "pch.h"
#include <array>

struct transform
{
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
};

class GameObject
{
public:
	virtual ~GameObject() = default;
	virtual void Init() {};
	virtual void Update(float deltatime) {};
	virtual void Draw(float deltatime) {};
	virtual void Dispose() {};
	transform GetTransform() const { return transform; }

protected:
	transform transform = {};
};
