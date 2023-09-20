#pragma once
#include "Definitions.h"
#include <windows.h>

class Buffer
{
public:
	Buffer(int Grid[], int size, int MaxLineSize);
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	int m_maxSize;
private:


};

