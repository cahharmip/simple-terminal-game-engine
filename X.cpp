#include <math.h>
#include "X.h"
#include "InputManager.h"
#include "BaseScene.h"
#include "Bullet.h"

void X::Init()
{
	CreateSprite();
	transform.position = { 0, 4 };
	InitCollision();
}

void X::Update(float deltaTime)
{
	m_current_state = {};
	m_current_state.direction = m_previous_state.direction;
	UpdateInput(deltaTime);
	CheckPositionState();
	UpdatePosition(deltaTime);
	UpdateCollision();
}

void X::Draw(float deltaTime)
{
	m_sprite.Draw(transform.position);
}

void X::OnMoveUp(float deltaTime)
{
	//Check if at the ladder
}

void X::OnMoveDown(float deltaTime)
{
	//Check if at the ladder
}

void X::OnMoveLeft(float deltaTime)
{
	m_current_state.movement_state = MovementState::MOVING;
	m_current_state.direction = Direction::LEFT;
}

void X::OnMoveRight(float deltaTime)
{
	m_current_state.movement_state = MovementState::MOVING;
	m_current_state.direction = Direction::RIGHT;
}

void X::OnMoveJump(float deltaTime)
{
	if (m_previous_state.jump_state == JUMPING_OVER)
	{
		m_current_state.jump_state = JUMPING_OVER;
		return;
	}

	if (m_previous_state.position_state != GROUNED && m_previous_state.jump_state != JUMPING) return;

	m_jump_time += deltaTime;
	if (m_jump_time < m_jump_max_duration)
	{
		m_current_state.jump_state = JUMPING;
	}
	else
	{
		m_current_state.jump_state = JUMPING_OVER;
	}
}

void X::OnMoveAttack(float deltaTime)
{
	m_current_state.attack_state = ATTACKING;
	m_cooldown_count += deltaTime;
	if (m_cooldown_count < ATTACK_COOLDOWN)
	{
		return;
	}
	m_cooldown_count = 0.0f;
	Bullet* bullet = m_owner_scene->InstantiateGameObject<Bullet>(BaseScene::LAYER::DEFAULT);
	bullet->transform.position = transform.position;
}

void X::OnMoveDash(float deltaTime)
{
	if (m_previous_state.property_state == DASHING_OVER)
	{
		m_current_state.property_state = DASHING_OVER;
		return;
	}

	m_dash_time += deltaTime;
	if (m_dash_time > m_dash_max_duration)
	{
		m_dash_time = 0.0f;
		m_current_state.property_state = DASHING_OVER; 
	}
	else
	{
		m_current_state.property_state = DASHING;
	}
}

void X::CreateSprite()
{
	char flat_color = 'X';
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

void X::CheckPositionState()
{
	if (transform.position.y > GROUND_Y)
	{
		m_current_state.position_state = PositionState::AIRBORNE;
	}
	else
	{
		transform.position.y = GROUND_Y;
		m_current_state.position_state = PositionState::GROUNED;
	}
}

void X::UpdatePosition(float deltaTime)
{
	float m_speed_x = 0.0f;
	float m_speed_y = 0.0f;

	//Property modifier
	if (m_current_state.property_state == PropertyState::DASHING)
	{
		m_speed_x = m_dash_speed * deltaTime;
	}
	else if (m_current_state.property_state == PropertyState::LADDERCLIMBING)
	{
		//m_speed_y = CLIMB_SPEED;
	}
	else if (m_current_state.property_state == NEUTRAL)
	{
		m_dash_time = 0.0f;
	}

	// Action modifier
	if (m_current_state.jump_state == JUMPING)
	{
		m_speed_y = m_jump_speed * (1 - m_jump_time / m_jump_max_duration) * deltaTime;
	}


	// Movement modifier
	if (m_current_state.movement_state == MOVING)
	{
		if (m_current_state.property_state != PropertyState::DASHING)
		{
			m_speed_x = DEFAULT_SPEED * deltaTime;
		}
	}

	// Position modifier
	if (m_current_state.position_state == AIRBORNE && m_current_state.jump_state != JUMPING)
	{
		m_jump_time = 0.0f;
		m_fall_time += deltaTime;
		m_speed_y = -m_fall_speed * (m_fall_time / m_fall_max_time) * deltaTime;
	}
	else if (m_current_state.position_state == GROUNED)
	{
		m_fall_time = 0.0f;
	}

	// Direction modifier
	if (m_current_state.direction == LEFT)
	{
		m_speed_x *= -1;
	}
	
	m_previous_state = m_current_state;
	transform.position.x += m_speed_x;
	transform.position.y += m_speed_y;
}

void X::InitCollision()
{
	m_collision.height = m_sprite.GetHeight();
	m_collision.width = m_sprite.GetWidth();
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}

void X::UpdateCollision()
{
	m_collision.x = transform.position.x - m_collision.width / 2.0f;
	m_collision.y = transform.position.y - m_collision.height / 2.0f;
}
