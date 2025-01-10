#include "Scene.h"

namespace yw 
{
	Scene::Scene()		
		: m_Layers{}
	{
		CreateLayers();
	}

	Scene::~Scene()
	{
	}

	void Scene::Init()
	{
		for (Layer* layer : m_Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Init();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : m_Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : m_Layers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : m_Layers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject, const LayerType type)
	{
		m_Layers[(UINT)type]->AddGameObject(gameObject);
	}

	void Scene::CreateLayers()
	{
		m_Layers.resize((UINT)LayerType::Max);
		for (size_t i = 0; i < (UINT)LayerType::Max; i++)
		{
			m_Layers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}
}

