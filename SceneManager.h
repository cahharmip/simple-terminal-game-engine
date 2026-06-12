#pragma once
#include "pch.h"
#include <unordered_map>
#include <memory>
#include "CharacterSelectScene.h"
#include "ExampleStageScene.h"

class IScene;

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}

	SceneManager()
	{
		RegisterScene("CharacterSelectScene", std::make_unique<CharacterSelectScene>());
		RegisterScene("ExampleStageScene", std::make_unique<ExampleStageScene>());
		setScene("CharacterSelectScene");
	}

	void RegisterScene(std::string sceneName, std::unique_ptr<IScene> sceneInstance);
	void setScene(std::string sceneName);
	IScene* GetCurrentScene() { return m_scenes_list[m_current_scene].get(); };
	void DisposeAllScene();
private:
	std::unordered_map<std::string, std::unique_ptr<IScene>> m_scenes_list;
	std::string m_current_scene;
};