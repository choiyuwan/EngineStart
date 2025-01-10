#pragma once
#include "Component.h"
#include "Maths.h"
namespace yw
{
	using namespace yw::maths;
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;	

		Vector2 CalculatePos(Vector2 pos) { return pos - m_Distance; };

	private:
		class GameObject* target;

		Vector2 m_Distance;
		Vector2 m_Resolution;
		Vector2 m_LookPos;		
	};
}


