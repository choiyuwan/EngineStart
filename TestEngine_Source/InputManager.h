#pragma once
#include "CommonInclude.h"
namespace yw
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class eKeyCode
	{
		Q, W, E, R, 
		A, S, D, 
		Left, Right, Down, Up,
		End,
	};
	class InputManager
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};
		static void Init();
		static void Update();
		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static void createKeys();
		static void UpdateKeys();
		static void UpdateKey(InputManager::Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(InputManager::Key& key);
		static void UpdateKeyUp(InputManager::Key& key);
	private:
		//eKeyState mState[] = eKeyState::Up;
		static vector<Key> Keys;
	};
}

