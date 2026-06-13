#include "ExampleStageScene.h"
#include "InputManager.h"
#include "SceneManager.h"

void ExampleStageScene::Init()
{
	player_x.Init();
	e_met.Init();
}

void ExampleStageScene::Update(float deltaTime)
{
	std::cout << "-----------Scene : Example Stage  -----------\n" ;
	if (InputManager::GetInstance().IsKeyPressed('c'))
	{
		SceneManager::GetInstance().setScene("CharacterSelectScene");
	}
	e_met.Update(deltaTime);
	player_x.Update(deltaTime);
}
void ExampleStageScene::Draw(float deltaTime)
{
	e_met.Draw(deltaTime);
	player_x.Draw(deltaTime);
}

void ExampleStageScene::Dispose()
{
}