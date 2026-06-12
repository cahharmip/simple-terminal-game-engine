#include "Renderer.h"

void Renderer::WriteOverCanvas(Vector2 worldPosition, std::vector<RenderIndexInfo> indicesInfo)
{
	//Draw index to screen m_canvas[y][x] assign
	for (auto& indexInfo : indicesInfo)
	{
		Vector2 screenPoint = {};
		//to world space -> to clip space
		screenPoint.x = indexInfo.index.x - indexInfo.origin.x + worldPosition.x;
		screenPoint.y = indexInfo.index.y - indexInfo.origin.y + HEIGHT - worldPosition.y;
		//check out of bound
		if (screenPoint.x < 0)
		{
			screenPoint.x = 0;
		}
		else if (screenPoint.x >= WIDTH)
		{
			screenPoint.x = WIDTH - 1;
		}

		if (screenPoint.y < 0)
		{
			screenPoint.y = 0;
		}
		else if (screenPoint.y >= HEIGHT)
		{
			screenPoint.y = HEIGHT - 1;
		}

		m_canvas[screenPoint.y][screenPoint.x] = indexInfo.color;
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