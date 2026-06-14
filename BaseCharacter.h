#pragma once
#include "GameObject.h"
#include "CSprite.h"

class BaseCharacter : public virtual GameObject
{
public:
	BaseCharacter() = delete;
	explicit BaseCharacter(BaseScene* scene) : GameObject(scene) {}
	~BaseCharacter() override = default;
protected:
	enum Direction
	{
		LEFT,
		RIGHT,
	};

	enum PropertyState
	{
		NEUTRAL,
		DASHING,
		DASHING_OVER, // This state for create trail.
		LADDERCLIMBING,
		DAMAGED,
	};

	enum AttackState
	{
		NO_ATTACK,
		ATTACKING
	};

	enum JumpState
	{
		NO_JUMP,
		JUMPING,
		JUMPING_OVER,
	};

	enum MovementState
	{
		IDLE,
		MOVING,
	};

	enum PositionState
	{
		GROUNED,
		WALL,
		AIRBORNE
	};

	struct CharacterState
	{
		Direction direction;
		PropertyState property_state;
		AttackState attack_state;
		JumpState jump_state;
		MovementState movement_state;
		PositionState position_state;
	};

	const float GROUND_Y = 4.0f;
	const float DEFAULT_SPEED = 10.0f;

	CharacterState m_current_state{ Direction::RIGHT, PropertyState::NEUTRAL , AttackState::NO_ATTACK, JumpState::NO_JUMP, MovementState::IDLE, PositionState::GROUNED };
	CharacterState m_previous_state{ Direction::RIGHT, PropertyState::NEUTRAL , AttackState::NO_ATTACK, JumpState::NO_JUMP, MovementState::IDLE, PositionState::GROUNED };

	float m_jump_speed = 50.0f;
	float m_jump_max_duration = 0.25f;
	float m_jump_time = 0.0f;
	float m_dash_speed = 30.0f;
	float m_dash_max_duration = 0.4f;
	float m_dash_time = 0.0f;
	float m_fall_speed = 40.0f;
	float m_fall_max_time = 0.5f;
	float m_fall_time = 0.0f;

	CSprite m_sprite;
};