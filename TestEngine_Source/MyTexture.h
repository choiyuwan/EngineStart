#pragma once
#include "Resource.h"
namespace yw
{
	class MyTexture : public Resource
	{
	public:
		enum class TextureType
		{
			Bmp,
			Png,
			None,
		};

		MyTexture();
		~MyTexture();
		

		virtual HRESULT Load(const std::wstring& path) override;
		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }	
		HDC GetHDC() { return m_Hdc; }
		TextureType GetTextureType() { return m_Type; }
	
	private:		
		
		HBITMAP m_Bitmap;
		HDC m_Hdc;
		UINT m_Width;
		UINT m_Height;
		TextureType m_Type;
	};
}


