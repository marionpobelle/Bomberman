#pragma once
#include <windows.h>

/*
===============================================================================
The NYTimer class allow the use of a precise timer for the Windows Console.
The source code was given to us as a starting point of the project.
===============================================================================
*/
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