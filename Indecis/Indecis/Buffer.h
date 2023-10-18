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
	Buffer(int _maxLineSize);
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	void UpdateConsole(Grid grid, std::vector<Transform*>& _entityList, UISystem uiSystem);
	void DrawFixedMap(Grid grid);

	int maxSize;
	int charsTab[SCREEN_HEIGHT][SCREEN_WIDTH];
	int xGameWindowPosition = 0;
	int yGameWindowPosition = 0;

private:
	void DrawBox(int coordX, int coordY);
	void DrawCharVisual(int _x, int _y, char _charVisual);
	void DrawBackground(int _x, int _y, char _charVisual);
	void FillTabWalls(int coordX, int coordY, Grid& grid);
	void FillTabGround(int coordX, int coordY);

	//ui's methods
	void DrawUI(UISystem _uiSystem, Grid& grid);
	void DrawWindow(UIWindow& _window);
	void PaintUISpriteInBuffer(int coordX, int coordY, std::string sprite, Grid& grid);


	void PaintCharactersInBuffer(int _charsTab[SCREEN_HEIGHT][SCREEN_WIDTH], Grid grid);
	void PaintSpriteInBuffer(int coordX, int coordY, std::string sprite, Grid& grid);
};

