#pragma once
#include "IScene.h"
#include <vector>
#include <array>
#include <memory>
#include "GameObject.h"

static const int MAX_LAYER = 4;

class BaseScene : public IScene
{
public:

	enum LAYER
	{
		BACKGROUND,
		DEFAULT,
		FOREGROUND,
		UI
	};

	virtual ~BaseScene() override = default;
	template <typename T>
	T* InstantiateGameObject(int layer)
	{
		std::unique_ptr<T> obj = std::make_unique<T>(this);
		obj->Init();
		T* rawPtr = obj.get();
		pendingAddGameObjectList[layer].push_back(std::move(obj));
		return rawPtr;
	}

	template <typename T>
	T* GetGameObject()
	{
		//TODO: Find GameObject In List (check match type)
		return gameObjectsList[0][0];
	}

	bool IsOverlap(Rect a, Rect b) // x, y top left
	{
		return a.x < b.x + b.width &&
			a.x + a.width > b.x &&
			a.y < b.y + b.height &&
			a.y + a.height > b.y;
	}

protected:
	std::array<std::vector<std::unique_ptr<GameObject>>, MAX_LAYER> gameObjectsList;
	std::array<std::vector<std::unique_ptr<GameObject>>, MAX_LAYER> pendingAddGameObjectList;
};