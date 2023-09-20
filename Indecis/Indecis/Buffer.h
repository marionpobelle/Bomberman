#pragma once
#include "Definitions.h"
#include <windows.h>

class Buffer
{
public:
	Buffer(int maxLineSize); 
	static CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	static void UpdateConsole(int Grid[], int size);

	static int m_maxSize;
private:


};

