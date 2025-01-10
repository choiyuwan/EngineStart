#pragma once
#include "..//TestEngine_Source//Script.h"
namespace yw
{
	class PlayerScript : public Script
	{
	public:

		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}

