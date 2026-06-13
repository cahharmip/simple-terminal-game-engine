#pragma once
#include "pch.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Renderer.h"
#include <chrono>
#include <thread>

int main()
{
	int fps = 45;
	int n = 0;
	const auto frame_duration = std::chrono::milliseconds(static_cast<int>(std::ceil(1.0f / fps * 1000.0f)));
	auto prev = std::chrono::steady_clock::now();
	std::cout << "\033[?25l";
	//----------    INIT    -----------
	SceneManager::GetInstance();
	//---------------------------------
	
	while (true) 
	{
		//---------- Begin Frame ----------
		auto const now = std::chrono::steady_clock::now();
		long long delta_milli = std::chrono::duration_cast<std::chrono::milliseconds>(now - prev).count();
		float deltaTime = delta_milli / 1000.0f;
		std::cout << "\033[H";
		std::cout << std::fixed << std::setprecision(7);
		std::cout << "Rendering at stable FPS :" << deltaTime << "\n";
		std::cout << "Frame Numbers : " << ++n << "\n";
		Renderer::GetInstance().BeginFrame();
		//---------------------------------

		//----------   UPDATE   -----------
		bool quit = InputManager::GetInstance().Update();
		SceneManager::GetInstance().GetCurrentScene()->Update(deltaTime);
		//---------------------------------

		//----------    Draw    -----------
		SceneManager::GetInstance().GetCurrentScene()->Draw(deltaTime);
		//---------------------------------

		//----------- End Frame -----------
		Renderer::GetInstance().EndFrame();
		InputManager::GetInstance().Clear();
		if (quit) break;
		auto const frame_end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(frame_end - now);
		prev = now;
		if (elapsed < frame_duration) 
		{
			std::this_thread::sleep_for(frame_duration - elapsed);
		}
		//---------------------------------
	}

	//dispose
	SceneManager::GetInstance().DisposeAllScene();
	return 0;
}