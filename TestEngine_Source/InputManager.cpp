#include "InputManager.h"
namespace yw
{
	vector<InputManager::Key> InputManager::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'A', 'S' ,'D',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
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
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

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
		if (IsKeyDown(key.keyCode))
		{
			UpdateKeyDown(key);
		}
		else
		{
			UpdateKeyUp(key);
		}
	}

	bool InputManager::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void InputManager::UpdateKeyDown(InputManager::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void InputManager::UpdateKeyUp(InputManager::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
}