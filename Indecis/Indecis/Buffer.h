#pragma once
#include <windows.h>
#include <vector>;
#include "Entity.h"
#include "Definitions.h"

class Entity;

class Buffer
{
public:
	Buffer(int maxLineSize); 
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	void UpdateConsole(int Grid[], int size, std::vector<Entity*>& _entityList);

	int m_maxSize;
private:


};

