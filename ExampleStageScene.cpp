#include "ExampleStageScene.h"
#include "InputManager.h"
#include "SceneManager.h"

void ExampleStageScene::Init()
{
	player_z.Init();
	player_x.Init();
	e_met.Init();
}

void ExampleStageScene::Update(float deltaTime)
{
	std::cout << "-----------Scene : Example Stage  -----------\n" ;
	if (InputManager::GetInstance().IsTriggered('C'))
	{
		SceneManager::GetInstance().setScene("CharacterSelectScene");
	}
	e_met.Update(deltaTime);
	player_x.Update(deltaTime);
	player_z.Update(deltaTime);
}
void ExampleStageScene::Draw(float deltaTime)
{
	e_met.Draw(deltaTime);
	player_x.Draw(deltaTime);
	player_z.Draw(deltaTime);
}

void ExampleStageScene::Dispose()
{
}