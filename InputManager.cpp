#include "InputManager.h"
#include <conio.h>

bool InputManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		m_prev[i] = m_curr[i];
		m_curr[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
	}

	if (IsPressed('Q'))
	{
		return true;
	}
	return false;
}

void InputManager::Clear()
{
}