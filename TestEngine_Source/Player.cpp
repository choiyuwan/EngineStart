#include "Player.h"
#include "InputManager.h"
#include "Transform.h"
#include "TimeControl.h"

namespace yw
{
	void Player::Init()
	{
		GameObject::Init();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (InputManager::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x += 100.0f * TimeControl::GetDeltaTime();
			tr->SetPos(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}