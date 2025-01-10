#include "TimeControl.h"

LARGE_INTEGER TimeControl::CpuFrequency = {};
LARGE_INTEGER TimeControl::PrevFrequency = {};
LARGE_INTEGER TimeControl::CurFrequency = {};
float TimeControl::DeltaTime = 0.0f;

void TimeControl::Init()
{
	QueryPerformanceFrequency(&CpuFrequency);
	QueryPerformanceCounter(&CurFrequency);
}

void TimeControl::Update()
{
	QueryPerformanceCounter(&CurFrequency);
	float differenceFrequency
		= static_cast<float>(CurFrequency.QuadPart - PrevFrequency.QuadPart);
	DeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
	PrevFrequency.QuadPart = CurFrequency.QuadPart;
}
