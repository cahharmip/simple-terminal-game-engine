#include "InputManager.h"
#include <conio.h>

bool InputManager::Update()
{
	if (_kbhit()) {
		char ch = _getch();
		m_current_message = ch;
		if (ch == 'q')
		{
			return true;
		}
	}
	return false;
}

void InputManager::Clear()
{
	m_current_message = '\0';
}

bool InputManager::IsKeyPressed(char c) const 
{
	if (m_current_message==c) return true;

	return false;
}