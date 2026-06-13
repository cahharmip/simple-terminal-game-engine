#pragma once
#include "pch.h"
#include <vector>

struct RenderIndexInfo
{
	Vector2 origin;
	Vector2 index;
	char color;
};

class Renderer
{
public:
	static int const WIDTH = 50;
	static int const HEIGHT = 25;
	static Renderer& GetInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer() {
		memset(m_canvas, ':', sizeof(m_canvas));
	}
	void WriteOverCanvas(Vector2 worldPosition, std::vector<RenderIndexInfo> indicesInfo);
	void BeginFrame();
	void const EndFrame();
private:
	char m_canvas[HEIGHT][WIDTH];
};