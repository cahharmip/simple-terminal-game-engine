#include "CharacterSelectScene.h"
#include "InputManager.h"
#include "SceneManager.h"

void CharacterSelectScene::Init()
{
	
}

void CharacterSelectScene::Update(float deltaTime)
{
	std::cout << "-----------Scene : Character Select -----------\n";
	if (InputManager::GetInstance().IsTriggered('C'))
	{
		SceneManager::GetInstance().setScene("ExampleStageScene");
	}
	
}

void CharacterSelectScene::Draw(float deltaTime)
{
	
}

void CharacterSelectScene::Dispose()
{
}