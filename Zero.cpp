#include "Zero.h"
#include "InputManager.h"

void Zero::Init()
{
	CreateSprite();
	transform.position = { 10, 8 };
}

void Zero::Update(float deltaTime)
{
	if (InputManager::GetInstance().IsKeyPressed('w'))
	{
		transform.position.y += 1;
	}
	if (InputManager::GetInstance().IsKeyPressed('a'))
	{
		transform.position.x -= 1;
	}
	if (InputManager::GetInstance().IsKeyPressed('s'))
	{
		transform.position.y -= 1;
	}
	if (InputManager::GetInstance().IsKeyPressed('d'))
	{
		transform.position.x += 1;
	}
}

void Zero::Draw(float deltaTime)
{
	m_sprite.Draw(transform.position);
}

void Zero::CreateSprite()
{
	char flat_color = 'Z';
	Vector2 origin = { 2,3 };
	m_sprite.AddIndex({ origin, {2,0}, flat_color });
	m_sprite.AddIndex({ origin, {3,0}, flat_color });
	m_sprite.AddIndex({ origin, {4,0}, flat_color });
	m_sprite.AddIndex({ origin, {2,1}, flat_color });
	m_sprite.AddIndex({ origin, {3,1}, flat_color });
	m_sprite.AddIndex({ origin, {4,1}, flat_color });
	m_sprite.AddIndex({ origin, {2,2}, flat_color });
	m_sprite.AddIndex({ origin, {3,2}, flat_color });
	m_sprite.AddIndex({ origin, {1,3}, flat_color });
	m_sprite.AddIndex({ origin, {2,3}, flat_color });
	m_sprite.AddIndex({ origin, {3,3}, flat_color });
	m_sprite.AddIndex({ origin, {4,3}, flat_color });
	m_sprite.AddIndex({ origin, {0,4}, flat_color });
	m_sprite.AddIndex({ origin, {2,4}, flat_color });
	m_sprite.AddIndex({ origin, {4,4}, flat_color });
	m_sprite.AddIndex({ origin, {1,5}, flat_color });
	m_sprite.AddIndex({ origin, {3,5}, flat_color });
	m_sprite.AddIndex({ origin, {0,6}, flat_color });
	m_sprite.AddIndex({ origin, {1,6}, flat_color });
	m_sprite.AddIndex({ origin, {3,6}, flat_color });
	m_sprite.AddIndex({ origin, {4,6}, flat_color });
}