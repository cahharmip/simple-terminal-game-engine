#include "Renderer.h"
#include <cmath>

void Renderer::WriteOverCanvas(Vector2 worldPosition, std::vector<RenderIndexInfo> indicesInfo)
{
	//Draw index to screen m_canvas[y][x] assign
	for (auto& indexInfo : indicesInfo)
	{
		int screenPointX = 0;
		int screenPointY = 0;
		//to world space -> to clip space
		screenPointX = std::lround(indexInfo.index.x) - std::lround(indexInfo.origin.x) + std::lround(worldPosition.x);
		screenPointY = std::lround(indexInfo.index.y) - std::lround(indexInfo.origin.y) + HEIGHT - std::lround(worldPosition.y);
		//check out of bound
		if (screenPointX < 0)
		{
			screenPointX = 0;
		}
		else if (screenPointX >= WIDTH)
		{
			screenPointX = WIDTH - 1;
		}

		if (screenPointY < 0)
		{
			screenPointY = 0;
		}
		else if (screenPointY >= HEIGHT)
		{
			screenPointY = HEIGHT - 1;
		}

		m_canvas[screenPointY][screenPointX] = indexInfo.color;
	}
}

void Renderer::BeginFrame()
{
	memset(m_canvas, '.', sizeof(m_canvas));
}

void const Renderer::EndFrame()
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH;++j)
		{
			std::cout << m_canvas[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << std::flush;
}