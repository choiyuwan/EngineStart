#pragma once
#include "Scene.h"

namespace yw 
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const wstring& name) {

			T* scene = new T();
			m_CurScene = scene;

			scene->SetName(name);
			scene->Init();			
			m_Scenes.insert(make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const wstring& name);
		static Scene* GetCurScene() { return m_CurScene; }

			static void Init();
			static void Update();
			static void LateUpdate();
			static void Render(HDC hdc);
			
		private:
			static map<wstring, Scene*> m_Scenes;

			static Scene* m_CurScene;

	};
}


