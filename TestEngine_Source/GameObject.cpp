#include "GameObject.h"
#include "InputManager.h"
#include "TimeControl.h"
#include "Transform.h"

namespace yw
{
	GameObject::GameObject() 		
	{
		m_Components.resize((UINT)ComponentType::End);
		AddTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : m_Components)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Init()
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Init();
		}
	}

	void GameObject::Update() 
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}		
	}

	void GameObject::AddTransform()
	{
		AddComponent<Transform>();
	}
}
