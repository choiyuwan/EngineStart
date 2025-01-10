#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
#include "TestApplication.h"
namespace yw
{
	extern yw::TestApplication application;
	Camera::Camera()
		:Component(ComponentType::Camera), m_Distance(Vector2::One)
		, m_Resolution(Vector2(1600.0f, 900.f)), m_LookPos(Vector2::Zero), target(nullptr)
	{

	}
	Camera::~Camera()
	{

	}
	void Camera::Init()
	{
		m_Resolution.x = application.GetWidth();
		m_Resolution.y = application.GetHeight();

	}
	void Camera::Update()
	{
		if (target)
		{
			Transform* tr = target->GetComponent<Transform>();
			m_LookPos = tr->GetPos();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			m_LookPos = cameraTr->GetPos();
		}

		m_Distance = m_LookPos - (m_Resolution * 0.5f);
	}
	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{

	}
}