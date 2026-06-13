#pragma once
#include "EnemyMet.h"
#include "Renderer.h"

void EnemyMet::Init()
{
	CreateSprite();
	transform.position = { Renderer::WIDTH - 1, 1};
}

void EnemyMet::Update(float deltaTime)
{
	transform.position.x -= 2.0f * deltaTime;
}

void EnemyMet::Draw(float deltaTime)
{
	m_sprite.Draw(transform.position);
}

void EnemyMet::CreateSprite()
{
	char flat_color = 'E';
	Vector2 origin = { 1,1 };
	m_sprite.AddIndex({ origin, {1,0}, flat_color });
	m_sprite.AddIndex({ origin, {2,0}, flat_color });
	m_sprite.AddIndex({ origin, {0,1}, flat_color });
	m_sprite.AddIndex({ origin, {1,1}, flat_color });
	m_sprite.AddIndex({ origin, {2,1}, flat_color });
}