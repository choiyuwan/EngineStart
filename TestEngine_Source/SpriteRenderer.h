#pragma once
#include "Component.h"
#include "MyTexture.h"


namespace yw
{
	class SpriteRenderer : public Component
	{

	public:

		SpriteRenderer();
		~SpriteRenderer();
		 
		void Init() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(MyTexture* texture) { m_Texture = texture; }
		void SetSize(maths::Vector2 size) { m_Size = size; }

	private:
		MyTexture* m_Texture;
		maths::Vector2 m_Size;
	};
}


