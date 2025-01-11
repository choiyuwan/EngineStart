#pragma once
#include "Component.h"
#include "Animation.h"
#include "MyTexture.h"
using namespace yw::maths;
namespace yw
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(function<void()> func)
			{
				event = move(func);
			}

			void operator()()
			{
				if (event)
				{
					event;
				}
			}
			function<void()> event;
		};
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
		bool IsCompleteAnimation() { return m_CurAnimation->IsCompete(); }

	private:
		map<wstring, Animation*> m_Animations;
		Animation* m_CurAnimation;
		bool m_IsLoop;

		//Event
		Event m_StartEvent;
		Event m_CompleteEvent;
		Event m_EndEvent;
	};
}


