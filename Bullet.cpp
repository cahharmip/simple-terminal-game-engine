#include "Bullet.h"
#include "BaseEnemy.h"

void Bullet::Init()
{
	CreateSprite();
	InitCollision();
}

void Bullet::Update(float deltaTime)
{
	m_lifeTime += deltaTime;
	if (m_lifeTime > MAX_LIFETIME)
	{
		Destroy();
		return;
	}
	transform.position.x += 50.0f * deltaTime;
	UpdateCollision();
}

void Bullet::Draw(float deltaTime)
{
	m_sprite.Draw(transform.position);
}

void Bullet::Dispose()
{
}

void Bullet::OnCollide(GameObject* obj)
{
	if (dynamic_cast<BaseEnemy*>(obj) != nullptr)
	{
		obj->Destroy();
	}
}

void Bullet::CreateSprite()
{
	Vector2 origin = { 0,1 };
	m_sprite.AddIndex({ origin, {0,0}, '>' });
	m_sprite.AddIndex({ origin, {1,0}, ')' });
	m_sprite.AddIndex({ origin, {2,0}, ')'});
}

void Bullet::InitCollision()
{
	m_collision.height = m_sprite.GetHeight();
	m_collision.width = m_sprite.GetWidth();
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}

void Bullet::UpdateCollision()
{
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}
