#pragma once
#include "CommonInclude.h"
namespace yw 
{
	class GameObject;

	class Component
	{

	public:

		Component(ComponentType m_Type);
		~Component();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { m_Owner = owner; }
		GameObject* GetOwner() { return m_Owner; }
		ComponentType GetType() { return m_Type; }

	private:
		GameObject* m_Owner;
		ComponentType m_Type;
	};
}


