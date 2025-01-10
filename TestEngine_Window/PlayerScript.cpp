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
		if (InputManager::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x += 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x -= 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y -= 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
		if (InputManager::GetKey(eKeyCode::Down))
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
	}
}

