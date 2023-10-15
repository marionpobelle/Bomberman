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
    input.close();
}

int Grid::GetGridCoordinates(int x, int y) {
    int coordinates = y * gameGridWidth + x;
    return coordinates;
}

int Grid::GetRandomFloorCoordinates(std::vector<Transform*>& _entityList) {
    int coordinates;
    int x;
    int y;
    do {
        x = rand() % gameGridHeight;
        y = rand() % gameGridWidth;
        coordinates = y * gameGridWidth + x;
    } while (HasCollision(x, y, _entityList));
    return coordinates;
}

void Grid::GetRandomFloorCoordinatesRefs(float& x, float& y, std::vector<Transform*>& _entityList) {
    srand(time(0));
    do {
        x = rand() % gameGridHeight;
        y = rand() % gameGridWidth;
    } while (HasCollision(x, y, _entityList));
}

int Grid::GetXFromGridApprox(int gridCoord) {
    int x;
    x = gridCoord - gameGridWidth;
    return x;
}

int Grid::GetYFromGridApprox(int gridCoord) {
    int y;
    y = gridCoord / gameGridWidth;
    return y;
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

Transform* Grid::GetTransformHere(int _x, int _y, std::vector<Transform*>& _entityList) {
    for (int i = 0; i < _entityList.size(); i++)
    {
        if (_entityList[i]->position.x == _x && _entityList[i]->position.y == _y) {
            return _entityList[i];
        }
    }
    return nullptr;
}

bool Grid::HasCollisionWallOnly(int _x, int _y) {
    int nextStep = GetGridCoordinates(_x, _y);
    if (grid[nextStep] == 1) {
        return true;
    }
    else {
        return false;
    }
}
