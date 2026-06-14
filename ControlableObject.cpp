#include "ControlableObject.h"
#include "InputManager.h"

void ControlableObject::UpdateInput(float deltaTime)
{
	if (InputManager::GetInstance().IsPressed('W'))
	{
		OnMoveUp(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed('A'))
	{
		OnMoveLeft(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed('S'))
	{
		OnMoveDown(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed('D'))
	{
		OnMoveRight(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed(VK_SPACE))
	{
		OnMoveJump(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed('J'))
	{
		OnMoveDash(deltaTime);
	}
	if (InputManager::GetInstance().IsPressed('K'))
	{
		OnMoveAttack(deltaTime);
	}
	for (auto& fn : m_callbacks)
	{
		fn(deltaTime);
	}
}

void ControlableObject::AddCallback(std::function<void(float deltaTime)> callback)
{
	m_callbacks.push_back(callback);
}
