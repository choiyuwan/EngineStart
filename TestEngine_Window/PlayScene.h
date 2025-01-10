#pragma once
#include "..\\TestEngine_Source\\Scene.h";
namespace yw 
{
	class PlayScene : public Scene
	{

	public:
		PlayScene();
		~PlayScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:

	};
}


