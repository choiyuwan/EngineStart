#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Maths.h"
#include "Transform.h"

namespace yw::object
{
	template <typename T>
	static T* Instantiate(LayerType type)
	{
		T* gameobject = new T();
		Scene* curScene = SceneManager::GetCurScene();
		Layer* layer = curScene->GetLayer(type);
		layer->AddGameObject(gameobject);

		return gameobject;
	}

	template <typename T>
	static T* Instantiate(LayerType type, maths::Vector2 pos)
	{
		T* gameobject = new T();
		Scene* curScene = SceneManager::GetCurScene();
		Layer* layer = curScene->GetLayer(type);
		layer->AddGameObject(gameobject);

		Transform* tr = gameobject->GetComponent<Transform>();
		tr->SetPos(pos);

		return gameobject;
	}

};

