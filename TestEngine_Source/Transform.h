#pragma once
#include "Component.h"
#include "Maths.h"
namespace yw
{		
	using namespace maths;
	class Transform : public Component
	{
		
	public:

		Transform();
		~Transform();

		void Init() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPos(Vector2 pos) { m_Pos.x = pos.x; m_Pos.y = pos.y; }
		Vector2 GetPos() { return m_Pos; }

	private:
		Vector2 m_Pos;
	};
}


