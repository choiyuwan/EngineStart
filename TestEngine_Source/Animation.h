#pragma once
#include "Resource.h"
#include "MyTexture.h"
#include "Maths.h"
using namespace yw::maths;
namespace yw
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				:leftTop(Vector2::Zero), size(Vector2::Zero), offset(Vector2::Zero), duration(0.0f)
			{

			}
		};
		Animation();
		~Animation();

		HRESULT Load(const wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const wstring& name, MyTexture* spriteSheet, Vector2 leftTop,
			Vector2 size, Vector2 offset, UINT spriteLength, float duration);

		void Reset();

		bool IsCompete() { return m_IsComplete; }
		void SetAnimator(class Animator* animator) { m_Animator = animator; }
	
	private:
		class Animator* m_Animator;
		MyTexture* m_Texture;

		vector<Sprite> m_AnimationSheet;
		int m_Index;
		float m_Time;
		bool m_IsComplete;

	};
}


