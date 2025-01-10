#pragma once
#include "CommonInclude.h"
#include "Component.h";
namespace yw
{
	class GameObject
	{
	public:

		GameObject();
		~GameObject();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->SetOwner(this);
			m_Components[(UINT)component->GetType()] = component;			

			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : m_Components) {
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}
	private:
		void AddTransform();

	private:
		vector<Component*> m_Components;
	};
}