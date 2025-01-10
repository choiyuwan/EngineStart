#pragma once
#include "CommonInclude.h"
class TimeControl
{ 
public : 
	static void Init();
	static void Update();
	static float GetDeltaTime() { return DeltaTime; }

private:
	static LARGE_INTEGER CpuFrequency;
	static LARGE_INTEGER PrevFrequency;
	static LARGE_INTEGER CurFrequency;
	static float DeltaTime;

};

