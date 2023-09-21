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
	Buffer(int _maxLineSize, int _screenGridRatio);
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	void UpdateConsole(Grid grid, std::vector<Entity*>& _entityList);

	int maxSize;
	const int screenGridRatio;

private:
	void DrawBox(int coordX, int coordY);
	void DrawCharVisual(int _x, int _y, char _charVisual);
	void DrawBackground(int _x, int _y, char _charVisual);

};

