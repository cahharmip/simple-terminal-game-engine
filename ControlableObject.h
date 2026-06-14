#pragma once
#include "GameObject.h"
#include <functional>
#include <vector>

class ControlableObject: public virtual GameObject 
{
public:
	ControlableObject() = delete;
	explicit ControlableObject(BaseScene* scene): GameObject(scene) {}
	virtual ~ControlableObject() = default;
	void UpdateInput(float deltaTime);
	void AddCallback(std::function<void(float deltaTime)> callback);
	void SetEnable(bool enabled) { m_enabled = enabled; }
	virtual void OnMoveUp(float deltaTime) { transform.position.y += m_default_speed * deltaTime; }
	virtual void OnMoveDown(float deltaTime) { transform.position.y -= m_default_speed * deltaTime; }
	virtual void OnMoveLeft(float deltaTime) { transform.position.x -= m_default_speed * deltaTime;; }
	virtual void OnMoveRight(float deltaTime) { transform.position.x += m_default_speed * deltaTime;; }
	virtual void OnMoveJump(float deltaTime) {}
	virtual void OnMoveAttack(float deltaTime) {}
	virtual void OnMoveDash(float deltaTime) {}
private:
	bool m_enabled = true;
	const float m_default_speed = 10.0f;
	std::vector<std::function<void(float deltaTime)>> m_callbacks;
};