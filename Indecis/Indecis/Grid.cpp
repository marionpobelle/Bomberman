#include <string>
#include <iostream>
#include <fstream>
#include "Definitions.h"
#include "Grid.h"

Grid::Grid(int gameGridWidth, int gameGridHeight) : m_gameGridWidth(gameGridWidth), m_gameGridHeight(gameGridHeight), m_gameGridSize(0) {
    m_gameGridSize = m_gameGridWidth * m_gameGridHeight;
    grid = new int[m_gameGridSize];
}

void Grid::ReadAndAddFileToGrid(std::string fileName) {
    //Recuperer le contenu du fichier, regarde quel type d'objet c'est et affiche le char
    //dans le buffer en consequence
    std::ifstream input;
    input.open(fileName);
    char value;

    int gameGridWidth = m_gameGridWidth;
    int gameGridHeight = m_gameGridHeight;

    for (int i = 0; i < gameGridHeight; i++) {
        for (int j = 0; j < gameGridWidth; j++) {
            if (input.fail()) break;
            input >> value;
            int gridPos = (i * gameGridWidth) + j;
            grid[gridPos] = int(value - '0');
        }
    }
}

int Grid::GetGridCoordinates(int x, int y) {
    int coordinates = x * m_gameGridWidth + y;
    return coordinates;
}
