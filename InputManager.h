#pragma once
#include "pch.h"
#include <windows.h>

class InputManager
{
public:
	static InputManager& GetInstance()
	{
		static InputManager instance;
		return instance;
	}

	bool Update();

	bool IsPressed(int key) { return m_curr[key]; }
	bool IsTriggered(int key) { return m_curr[key] && !m_prev[key]; }
	bool IsReleased(int key) { return !m_curr[key] && m_prev[key]; }
	void Clear();

private:
	bool m_curr[256] = {};
	bool m_prev[256] = {};
};