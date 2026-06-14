#include "ExampleStageScene.h"
#include "InputManager.h"
#include "SceneManager.h"

void ExampleStageScene::Init()
{
	InstantiateGameObject<X>(LAYER::DEFAULT);
	InstantiateGameObject<EnemyMet>(LAYER::DEFAULT);
}

void ExampleStageScene::Update(float deltaTime)
{
	std::cout << "-----------Scene : Example Stage  -----------\n" ;
	if (InputManager::GetInstance().IsTriggered('C'))
	{
		SceneManager::GetInstance().setScene("CharacterSelectScene");
	}

	for (auto& layer : gameObjectsList)
	{
		for (auto& obj : layer)
		{
			obj->Update(deltaTime);
		}
	}

	CheckCollisionDefaultLayer();

	//Delete
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		auto& obj = gameObjectsList[i];

		std::erase_if(obj,
			[](const std::unique_ptr<GameObject>& obj)
			{
				return obj == nullptr || obj->IsDestroyed();
			});
	}

	//Add
	for (int i = 0; i < MAX_LAYER; ++i)
	{
		for (auto& obj : pendingAddGameObjectList[i])
		{
			gameObjectsList[i].push_back(std::move(obj));
		}
		pendingAddGameObjectList[i].clear();
	}

}
void ExampleStageScene::Draw(float deltaTime)
{
	for (auto& layer : gameObjectsList)
	{
		for (auto& obj : layer)
		{
			obj->Draw(deltaTime);
		}
	}
}

void ExampleStageScene::Dispose()
{
	for (auto& layer : gameObjectsList)
		layer.clear();
	for (auto& layer : pendingAddGameObjectList)
		layer.clear();
}

void ExampleStageScene::CheckCollisionDefaultLayer()
{
	if (gameObjectsList[LAYER::DEFAULT].size() < 2) return;
	for (int i = 0; i < gameObjectsList[LAYER::DEFAULT].size() - 1; ++i)
	{
		for (int j = i + 1; j < gameObjectsList[LAYER::DEFAULT].size(); ++j)
		{
			if (IsOverlap(gameObjectsList[LAYER::DEFAULT][i]->GetCollision(), gameObjectsList[LAYER::DEFAULT][j]->GetCollision()))
			{
				gameObjectsList[LAYER::DEFAULT][i]->OnCollide(gameObjectsList[LAYER::DEFAULT][j].get());
				gameObjectsList[LAYER::DEFAULT][j]->OnCollide(gameObjectsList[LAYER::DEFAULT][i].get());
			}
		}
	}
}
