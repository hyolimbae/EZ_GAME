#include "stdafx.h"
#include "GgaetIp.h"

TimeManager::TimeManager()
{
	startTime = GetTickCount();
}

float TimeManager::GetTime()
{
	return ((float)GetTickCount() - startTime) / 1000;
}

TimeManager* TimeManager::GetInstance()
{
	static TimeManager* instance = new TimeManager();
	return instance;
}

float TimeManager::GetDeltaTime()
{
	return deltaTime;
}

void TimeManager::SetDeltaTime(float _deltaTime)
{
	deltaTime = _deltaTime;
}