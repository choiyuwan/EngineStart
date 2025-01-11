#pragma once
#include "CommonInclude.h"

namespace yw
{
	using namespace maths;
	enum class KeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class KeyCode
	{
		Q, W, E, R, 
		A, S, D, 
		Left, Right, Down, Up,
		LButton, RButton, MButton,
		End,
	};
	class InputManager
	{
	public:
		struct Key
		{
			KeyCode keyCode;
			KeyState state;
			bool isPressed;
		};
		static void Init();
		static void Update();
		static bool GetKeyDown(KeyCode code) { return Keys[(UINT)code].state == KeyState::Down; }
		static bool GetKeyUp(KeyCode code) { return Keys[(UINT)code].state == KeyState::Up; }
		static bool GetKey(KeyCode code) { return Keys[(UINT)code].state == KeyState::Pressed; }
		static Vector2 GetMousePos() { return m_MousePos; }		

	private:
		static void createKeys();
		static void UpdateKeys();
		static void UpdateKey(InputManager::Key& key);
		static bool IsKeyDown(KeyCode code);
		static void UpdateKeyDown(InputManager::Key& key);
		static void UpdateKeyUp(InputManager::Key& key);
		static void GetMousPosByWindow();
		static void ClearKeys();		
	private:		
		static vector<Key> Keys;
		static Vector2 m_MousePos;
	};
}

