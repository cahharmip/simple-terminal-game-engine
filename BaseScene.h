#pragma once
#include "IScene.h"
#include <vector>
#include <array>
#include <memory>
#include "GameObject.h"

static const int MAX_LAYER = 4; //0-MAX -> Back to Front | 0: BG, 1: Layer1, 2: Layer2, 3: UI

class BaseScene : public IScene
{
public:
	virtual ~BaseScene() = default;
	template <typename T>
	T* InstantiateGameObject(int layer)
	{
		return gameObjectsList[0][layer];
	}

	template <typename T>
	T* GetGameObject()
	{
		return gameObjectsList[0][0];
	}

protected:
	std::array<std::vector<std::unique_ptr<GameObject>>, MAX_LAYER> gameObjectsList;
	std::array<std::vector<std::unique_ptr<GameObject>>, MAX_LAYER> pendingAddGameObjectList;
};