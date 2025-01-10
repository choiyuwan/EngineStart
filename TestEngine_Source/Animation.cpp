#include "Animation.h"
#include "TimeControl.h"
#include "Animator.h"
#include "Transform.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Camera.h"
#include "MyTexture.h"
namespace yw
{
	Animation::Animation()
		:Resource(ResourceType::Animation), m_Animator(nullptr), m_Texture(nullptr), 
		m_AnimationSheet{},m_Index(-1), m_IsComplete(false), m_Time(0.0f)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (m_IsComplete)
			return;

		m_Time += TimeControl::GetDeltaTime();

		if (m_AnimationSheet[m_Index].duration < m_Time)
		{
			if (m_Index < m_AnimationSheet.size() - 1)
			{
				++m_Index;
			}
			else
			{
				m_IsComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
	
		if (m_Texture == nullptr)
			return;

		GameObject* gameObj = m_Animator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (renderer::mainCamera)
		{
			pos = renderer::mainCamera->CalculatePos(pos);
		}

		MyTexture::TextureType type = m_Texture->GetTextureType();

		if (type == MyTexture::TextureType::Bmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;

			Sprite sprite = m_AnimationSheet[m_Index];
			HDC imgHdc = m_Texture->GetHDC();

			AlphaBlend(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc
				, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
		}
		else if (type == MyTexture::TextureType::Png)
		{

		}
		
	}
	void Animation::CreateAnimation(const wstring& name, MyTexture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		m_Texture = spriteSheet;
		for (size_t i = 0; i < spriteLength; ++i)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			m_AnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		m_Time = 0.0f;
		m_Index = 0;
		m_IsComplete = false;
	}
}
