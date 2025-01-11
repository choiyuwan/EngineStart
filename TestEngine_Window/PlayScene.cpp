#include "PlayScene.h"
#include "Object.h"
#include "Player.h"
#include "ResourceManager.h"
#include "PlayerScript.h"
namespace yw 
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Init()
	{		
		Player* player = object::Instantiate<Player>(LayerType::Player, Vector2(100.f, 100.f));
		player->AddComponent<PlayerScript>();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
	}
}

