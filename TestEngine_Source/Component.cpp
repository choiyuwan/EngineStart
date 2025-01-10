#include "Component.h"

namespace yw
{
	Component::Component(ComponentType type)
		:m_Owner(nullptr), m_Type(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Init()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}

