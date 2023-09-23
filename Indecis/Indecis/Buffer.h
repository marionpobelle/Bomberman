#pragma once
#include <windows.h>
#include <vector>
#include "Grid.h"
#include "Transform.h"
#include "Definitions.h"


class Transform;

class Buffer
{
public:
	Buffer(int _maxLineSize, int _screenGridRatio);
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	void UpdateConsole(Grid grid, std::vector<Transform*>& _entityList);

	int maxSize;
	const int screenGridRatio;
	int charsTab[SCREEN_HEIGHT][SCREEN_WIDTH];

private:
	void DrawBox(int coordX, int coordY);
	void DrawCharVisual(int _x, int _y, char _charVisual);
	void DrawBackground(int _x, int _y, char _charVisual);
	void FillTabWalls(int coordX, int coordY);
	void FillTabGround(int coordX, int coordY);

	void PaintCharactersInBuffer(int _charsTab[SCREEN_HEIGHT][SCREEN_WIDTH]);


};

