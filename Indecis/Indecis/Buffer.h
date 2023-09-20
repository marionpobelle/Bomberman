#pragma once
#include <windows.h>
#include <vector>;
#include "Entity.h"
#include "Definitions.h"

class Buffer
{
public:
	Buffer(int maxLineSize); 
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	static void UpdateConsole(int Grid[], int size, std::vector<Entity*> entityList);

	int m_maxSize;
private:


};

