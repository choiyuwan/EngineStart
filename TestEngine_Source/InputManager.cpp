#include "InputManager.h"
#include "TestApplication.h"
extern yw::TestApplication application;
namespace yw
{
	vector<InputManager::Key> InputManager::Keys = {};
	Vector2 InputManager::m_MousePos = Vector2::One;

	int ASCII[(UINT)KeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'A', 'S' ,'D',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON,
	};

	void InputManager::Init()
	{
		createKeys();
	}

	void InputManager::Update()
	{
		UpdateKeys();
	}
	
	void InputManager::createKeys()
	{
		for (size_t i = 0; i < (UINT)KeyCode::End; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.state = KeyState::None;
			key.keyCode = (KeyCode)i;

			Keys.push_back(key);
		}
	}

	void InputManager::UpdateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				UpdateKey(key);
			});
	}

	void InputManager::UpdateKey(InputManager::Key& key)
	{
		if (GetFocus())
		{
			if (IsKeyDown(key.keyCode))
			{
				UpdateKeyDown(key);
			}
			else
			{
				UpdateKeyUp(key);
			}

			GetMousPosByWindow();
		}
		else
		{
			ClearKeys();
		}
		
	}

	bool InputManager::IsKeyDown(KeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void InputManager::UpdateKeyDown(InputManager::Key& key)
	{
		if (key.isPressed == true)
			key.state = KeyState::Pressed;
		else
			key.state = KeyState::Down;

		key.isPressed = true;
	}

	void InputManager::UpdateKeyUp(InputManager::Key& key)
	{
		if (key.isPressed == true)
			key.state = KeyState::Up;
		else
			key.state = KeyState::None;

		key.isPressed = false;
	}

	void InputManager::GetMousPosByWindow()
	{

		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		m_MousePos.x = mousePos.x;
		m_MousePos.y = mousePos.y;

	}

	void InputManager::ClearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == KeyState::Down || key.state == KeyState::Pressed)
			{
				key.state = KeyState::Up;
			}
			else if (key.state == KeyState::Up)
			{
				key.state = KeyState::None;
			}

			key.isPressed = false;
		}
	}
}