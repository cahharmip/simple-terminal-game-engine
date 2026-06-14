#pragma once
#include "pch.h"
#include <vector>
#include "Renderer.h"

class CSprite
{
	public:
		void Draw(Vector2 position);
		void AddIndex(RenderIndexInfo info);
		int GetWidth()
		{
			if (m_width != -1) return m_width;

			int max = 0;
			for (const RenderIndexInfo& indexInfo : m_indices)
			{
				if (indexInfo.index.x > max)
				{
					max = static_cast<int>(indexInfo.index.x);
				}
			}
			m_width = max + 1;
			return m_width;
		}

		int GetHeight()
		{
			if (m_height != -1) return m_height;

			int max = 0;
			for (const RenderIndexInfo& indexInfo : m_indices)
			{
				if (indexInfo.index.y > max)
				{
					max = static_cast<int>(indexInfo.index.y);
				}
			}
			m_height = max + 1;
			return m_height;
		}
	private:
		std::vector<RenderIndexInfo> m_indices;
		int m_width = -1;
		int m_height = -1;
};