#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

namespace yw
{
	class Layer
	{

	public:
		Layer();
		~Layer();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		//eLayerType mType;
		std::vector<GameObject*> m_GameObjects;
	};
}


