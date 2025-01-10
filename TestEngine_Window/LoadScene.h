#pragma once
#pragma once
#include "..\\TestEngine_SOURCE\\SceneManager.h"
#include "..\\TestEngine_SOURCE\\ResourceManager.h"
#include "..\\TestEngine_SOURCE\\MyTexture.h"
#include "PlayScene.h"

namespace yw
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}

	void LoadResources()
	{
		//ResourceManager::Load<MyTexture>(L"Player", L"..\\Resources\\test1.png\\");
	}
}