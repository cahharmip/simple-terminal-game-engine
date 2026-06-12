#pragma once
#include "pch.h"
#include <Windows.h>

class InputManager
{
public:
	static InputManager& GetInstance()
	{
		static InputManager instance;
		return instance;
	}

	bool Update();

	bool IsKeyPressed(char c) const;

	void Clear();

private:
	char m_current_message;
};