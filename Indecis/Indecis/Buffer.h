#pragma once
#include <windows.h>
#include <vector>
#include "Grid.h"
#include "Entity.h"
#include "Definitions.h"

class Entity;

class Buffer
{
public:
	Buffer(int maxLineSize, int screenGridRatio);
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	void UpdateConsole(Grid grid, std::vector<Entity*>& _entityList);

	int m_maxSize;
	const int m_screenGridRatio;

private:
	void DrawBox(int coordX, int coordY);

};

