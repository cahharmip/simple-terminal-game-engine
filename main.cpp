#pragma once
#include "pch.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Renderer.h"
#include <chrono>
#include <thread>

int main()
{
	int fps = 15;
	int n = 0;
	const auto frame_duration = std::chrono::milliseconds(static_cast<int>(std::ceil(1.0f / fps * 1000)));
	const auto last_frame = std::chrono::steady_clock::now();
	std::cout << "\033[?25l";
	//----------    INIT    -----------
	SceneManager::GetInstance();
	//---------------------------------
	
	while (true) 
	{
		//---------- Begin Frame ----------
		auto frame_start = std::chrono::steady_clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(frame_start - last_frame).count() * 1000.0f;
		std::cout << "\033[H";
		std::cout << "Rendering at stable FPS...\n";
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
		auto frame_end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(frame_end - frame_start);
		const auto last_frame = std::chrono::steady_clock::now();
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