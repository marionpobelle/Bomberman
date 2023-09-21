#pragma once
#include <windows.h>

class NYTimer
{
public:
	static LARGE_INTEGER lastUpdateTime;
	static LONGLONG freq;
	static float deltaTime;

	NYTimer(); //constructor
	static void Start(void);
	static float getElapsedSeconds(bool restart = false);
	static void deltaTimeCalcul();
	static unsigned long getElapsedMs(bool restart = false);
};