#include "SceneManager.h"
#include "IScene.h"

void SceneManager::RegisterScene(std::string name, std::unique_ptr<IScene> scene)
{
	m_scenes_list.insert({ name, std::move(scene) });
}

void SceneManager::setScene(std::string name)
{
	if (m_current_scene != "") m_scenes_list[m_current_scene]->Dispose();
	m_current_scene = name;
	m_scenes_list[m_current_scene]->Init();
}

void SceneManager::DisposeAllScene()
{
	//
}
