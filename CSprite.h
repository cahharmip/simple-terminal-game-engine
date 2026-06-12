#pragma once
#include "pch.h"
#include <vector>
#include "Renderer.h"

class CSprite
{
	public:
		void Draw(Vector2 position);
		void AddIndex(RenderIndexInfo info);
	private:
		std::vector<RenderIndexInfo> m_indices;
};