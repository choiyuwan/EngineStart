#pragma once
#include "CommonInclude.h";
#include "GameObject.h"
namespace yw
{
	class TestApplication
	{
	public:
		TestApplication();
		~TestApplication();

		void Init(HWND hWnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HWND GetHwnd() { return m_hWnd; }
		HDC GetHdc() { return m_Hdc; }
		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }

	private:
		void ClearRenderTarget();
		void CopyRenderTarget(HDC sorce, HDC dest);
		void AdjustWindow(HWND hWnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitEtc();

	private:
		HWND m_hWnd;
		HDC m_Hdc;	

		HDC m_BackHdc;
		HBITMAP m_BackBitmap;

		UINT m_Width;
		UINT m_Height;
	};

}

