#include "CSprite.h"

void CSprite::Draw(Vector2 position)
{
	Renderer::GetInstance().WriteOverCanvas(position, m_indices);
}

void CSprite::AddIndex(RenderIndexInfo info)
{
	m_indices.push_back(info);
}