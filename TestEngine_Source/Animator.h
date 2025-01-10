#pragma once
#include "Component.h"
#include "Animation.h"
#include "MyTexture.h"
#include "Maths.h"
using namespace yw::maths;
namespace yw
{
	class Animator : public Component
	{
	public:
		Animator(ComponentType m_Type);
		~Animator();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const wstring& name, MyTexture* spriteSheet, Vector2 leftTop, 
			Vector2 size, Vector2 offset, UINT spriteLength, float duration);

		Animation* FindAnimation(const wstring& name);
		void PlayAnimation(const wstring& name, bool isLoop = true);

	private:
		map<wstring, Animation*> m_Animations;
		Animation* m_CurAnimation;
		bool m_IsLoop;
	};
}


