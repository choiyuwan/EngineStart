#include "MyTexture.h"
#include "TestApplication.h"

namespace yw
{
	MyTexture::MyTexture()
		:Resource(ResourceType::Texture)
	{
	}

	MyTexture::~MyTexture()
	{
	}

	HRESULT MyTexture::Load(const std::wstring& path)
	{		

		return S_OK;
	}
}

