#pragma once
#include <windows.h>

class NYTimer
{
public:
	static LARGE_INTEGER lastUpdateTime;
	static LONGLONG freq;

	NYTimer(); //constructor
	static void Start(void);
	static float getElapsedSeconds(bool restart = false); 
	static unsigned long getElapsedMs(bool restart = false);
};