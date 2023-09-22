#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Definitions.h"
#include "Grid.h"
#include "Transform.h"

Grid::Grid(int gameGridWidth, int gameGridHeight) : gameGridWidth(gameGridWidth), gameGridHeight(gameGridHeight), gameGridSize(0) {
    gameGridSize = gameGridWidth * gameGridHeight;
    grid = new int[gameGridSize];
}

void Grid::ReadAndAddFileToGrid(std::string fileName) {
    //Recuperer le contenu du fichier, regarde quel type d'objet c'est et affiche le char
    //dans le buffer en consequence
    std::ifstream input;
    input.open(fileName);
    char value;

    int Width = gameGridWidth;
    int Height = gameGridHeight;

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
    int coordinates = y * gameGridWidth + x;
    return coordinates;
}

bool Grid::HasTransformHere(int _x, int _y, std::vector<Transform*>& _entityList) {
    for (int i = 0; i < _entityList.size(); i++)
    {
        if (_entityList[i]->position.x == _x && _entityList[i]->position.y == _y) {
            return true;
        }
    }
    return false;
}

bool Grid::HasCollision(int _x, int _y, std::vector<Transform*>& _entityList) {
    int nextStep = GetGridCoordinates(_x, _y);
    if (grid[nextStep] == 0) { // si il n'y a pas de mur
        if (HasTransformHere(_x, _y, _entityList)) // si il y a un transform
            return true;
        else return false; // si il n'y a pas de transform
    }
    else // si il y a un mur
        return true;
}
