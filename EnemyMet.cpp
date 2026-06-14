#include "EnemyMet.h"
#include "Renderer.h"

void EnemyMet::Init()
{
	CreateSprite();
	transform.position = { Renderer::WIDTH , m_sprite.GetHeight() / 2.0f };
	InitCollision();
}

void EnemyMet::Update(float deltaTime)
{
	transform.position.x -= 5.0f * deltaTime;
	UpdateCollision();
}

void EnemyMet::Draw(float deltaTime)
{
	m_sprite.Draw(transform.position);
}

void EnemyMet::CreateSprite()
{
	char flat_color = 'E';
	Vector2 origin = { 1,3 };
	m_sprite.AddIndex({ origin, {1,0}, flat_color });
	m_sprite.AddIndex({ origin, {2,0}, flat_color });
	m_sprite.AddIndex({ origin, {0,1}, flat_color });
	m_sprite.AddIndex({ origin, {1,1}, flat_color });
	m_sprite.AddIndex({ origin, {2,1}, flat_color });
	m_sprite.AddIndex({ origin, {3,1}, flat_color });
	m_sprite.AddIndex({ origin, {0,2}, flat_color });
	m_sprite.AddIndex({ origin, {1,2}, flat_color });
	m_sprite.AddIndex({ origin, {2,2}, flat_color });
	m_sprite.AddIndex({ origin, {3,2}, flat_color });
	m_sprite.AddIndex({ origin, {0,3}, flat_color });
	m_sprite.AddIndex({ origin, {1,3}, flat_color });
	m_sprite.AddIndex({ origin, {2,3}, flat_color });
	m_sprite.AddIndex({ origin, {3,3}, flat_color });
	m_sprite.AddIndex({ origin, {0,4}, flat_color });
	m_sprite.AddIndex({ origin, {1,4}, flat_color });
	m_sprite.AddIndex({ origin, {2,4}, flat_color });
	m_sprite.AddIndex({ origin, {3,4}, flat_color });
	m_sprite.AddIndex({ origin, {0,5}, flat_color });
	m_sprite.AddIndex({ origin, {1,5}, flat_color });
	m_sprite.AddIndex({ origin, {2,5}, flat_color });
	m_sprite.AddIndex({ origin, {3,5}, flat_color });
}

void EnemyMet::InitCollision()
{
	m_collision.height = m_sprite.GetHeight();
	m_collision.width = m_sprite.GetWidth();
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}

void EnemyMet::UpdateCollision()
{
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}
