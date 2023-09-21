#pragma once
/* Includes:
#include <string>

*/

class Grid
{
public:
	Grid(int gameGridWidth, int gameGridHeight)	;
	void ReadAndAddFileToGrid(std::string fileName);

	int *grid;
	int m_gameGridSize;
private:
	const int m_gameGridWidth = 10;
	const int m_gameGridHeight = 10;
};

