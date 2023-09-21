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
	int gameGridSize;
private:
	const int gameGridWidth = 10;
	const int gameGridHeight = 10;
};

