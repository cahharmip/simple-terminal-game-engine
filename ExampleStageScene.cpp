#include "ExampleStageScene.h"
#include "InputManager.h";
#include "SceneManager.h";

void ExampleStageScene::Init()
{
	player_x.Init();
	player_zero.Init();
}

void ExampleStageScene::Update(float deltaTime)
{
	std::cout << "-----------Scene : Example Stage  -----------\n" ;
	if (InputManager::GetInstance().IsKeyPressed('c'))
	{
		SceneManager::GetInstance().setScene("CharacterSelectScene");
	}
	player_x.Update(deltaTime);
	player_zero.Update(deltaTime);
}
void ExampleStageScene::Draw(float deltaTime)
{
	player_x.Draw(deltaTime);
	player_zero.Draw(deltaTime);
}
void ExampleStageScene::Dispose()
{
}