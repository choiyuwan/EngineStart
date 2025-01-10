#include "TestApplication.h"
#include "InputManager.h"
#include "TimeControl.h"
#include "SceneManager.h"

namespace yw
{
	TestApplication::TestApplication()
		:m_hWnd(nullptr), m_Hdc(nullptr), m_Width(0), m_Height(0),m_BackHdc(NULL), m_BackBitmap(NULL)
	{

	}

	TestApplication::~TestApplication()
	{

	}
	void TestApplication::Init(HWND hWnd, UINT width, UINT height)
	{
		
		AdjustWindow(hWnd, width, height);
		CreateBuffer(width, height);
		InitEtc();

		SceneManager::Init();
	}

	void TestApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void TestApplication::Update()
	{		
		InputManager::Update();
		TimeControl::Update();

		SceneManager::Update();
	}

	void TestApplication::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void TestApplication::Render()
	{
		ClearRenderTarget();		
		
		SceneManager::Render(m_BackHdc);

		CopyRenderTarget(m_BackHdc, m_Hdc);
	}

	void TestApplication::ClearRenderTarget()
	{
		Rectangle(m_BackHdc, -1, -1, 1601, 901);
	}
	void TestApplication::CopyRenderTarget(HDC sorce, HDC dest)
	{
		BitBlt(dest, 0, 0, m_Width, m_Height, sorce, 0, 0, SRCCOPY);
	}


	void TestApplication::AdjustWindow(HWND hWnd, UINT width, UINT height)
	{
		m_hWnd = hWnd;
		m_Hdc = GetDC(hWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		ShowWindow(m_hWnd, true);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;
		SetWindowPos(m_hWnd, nullptr, 0, 0, m_Width, m_Height, 0);
	}

	void TestApplication::CreateBuffer(UINT width, UINT height)
	{

		m_BackBitmap = CreateCompatibleBitmap(m_Hdc, width, height);
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(m_BackHdc, m_BackBitmap);
		DeleteObject(oldBitMap);
	}

	void TestApplication::InitEtc()
	{

		InputManager::Init();
		TimeControl::Init();
	}
}

