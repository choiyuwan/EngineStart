#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
#include "Layer.h"
namespace yw
{
	class Scene
	{

	public:

		Scene();
		~Scene();

		virtual  void Init();
		virtual  void Update();
		virtual  void LateUpdate();
		virtual  void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const LayerType type);

		void SetName(const wstring& name) { m_SceneName = name; }
		Layer* GetLayer(LayerType type) { return m_Layers[(UINT)type]; }


	private:
		void CreateLayers();

	private :
		vector<Layer*> m_Layers;
		wstring m_SceneName;
	};
}

