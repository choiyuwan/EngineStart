#include "PlayerScript.h"
#include "InputManager.h"
#include "Transform.h"
#include "TimeControl.h"
#include "GameObject.h"

namespace yw
{
	PlayerScript::PlayerScript()
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Init()
	{
	}

	void PlayerScript::Update()
	{
		if (InputManager::GetKey(KeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x += 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(KeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x -= 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(KeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y -= 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(KeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y += 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
		if (InputManager::GetKey(KeyCode::LButton)) {

			maths::Vector2 pos = InputManager::GetMousePos();
			wchar_t str[50] = L"";
			swprintf_s(str, 50, L"PosX : %d // PosY : %d", (int)pos.x, (int)pos.y);
			int len = wcsnlen_s(str, 50);

			TextOut(hdc, 0, 0, str, len);
		}
	}
}

