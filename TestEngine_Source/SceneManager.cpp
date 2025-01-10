#include "SceneManager.h"

namespace yw 
{
	map<wstring, Scene*> SceneManager::m_Scenes = {};
	Scene* SceneManager::m_CurScene = nullptr;

	void SceneManager::Init()
	{

	}

	void SceneManager::Update()
	{
		m_CurScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		m_CurScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		m_CurScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= m_Scenes.find(name);

		if (iter == m_Scenes.end())
			return nullptr;

		m_CurScene = iter->second;

		return iter->second;
	}
}

