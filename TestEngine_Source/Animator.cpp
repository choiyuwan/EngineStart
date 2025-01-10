#include "Animator.h"

namespace yw
{
	Animator::Animator(ComponentType m_Type)
		:Component(ComponentType::Animator), m_Animations{}, m_CurAnimation(nullptr), m_IsLoop(false)
	{
	}
	Animator::~Animator()
	{
	}
	void Animator::Init()
	{
	}
	void Animator::Update()
	{
		if (m_CurAnimation)
		{
			m_CurAnimation->Update();
			if (m_CurAnimation->IsCompete() == true && m_IsLoop == true)
			{
				m_CurAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (m_CurAnimation)
			m_CurAnimation->Render(hdc);
	}
	void Animator::CreateAnimation(const wstring& name, MyTexture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
			return;
		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);

		animation->SetAnimator(this);

		m_Animations.insert(make_pair(name, animation));
	};
	Animation* Animator::FindAnimation(const wstring& name)
	{
		auto iter = m_Animations.find(name);
		if (iter == m_Animations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::PlayAnimation(const wstring& name, bool isLoop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		m_CurAnimation = animation;
		m_CurAnimation->Reset();
		m_IsLoop = isLoop;
	}
}