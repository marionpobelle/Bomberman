#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>;
#include "Grid.h"
#include "Buffer.h"
#include "Entity.h"

using namespace std;

Buffer::Buffer(int _maxLineSize, int _screenGridRatio) : maxSize(_maxLineSize), screenGridRatio(_screenGridRatio)
{

}

void Buffer::UpdateConsole(Grid grid, std::vector<Entity*>& _entityList) {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
    dwBufferCoord, &rcRegion);

    //Lecture de la grid vers le buffer
    for (int i = 0; i < grid.gameGridSize; ++i) {
        int coordY = (int)ceil(i / maxSize);
        int coordX = i % maxSize;
        if (grid.grid[i] == 1) {
            DrawBox(coordX, coordY);
        }
        else {
            DrawBackground(coordX, coordY, 'A');
        }
    }

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {   
            //buffer[i][j].Char.UnicodeChar = 0x2580;
            //buffer[i][j].Attributes = 0x0001 + 0x0010;
            for (int e = 0; e < _entityList.size(); e++)
            {
                int _entityX = floor(_entityList[e]->position.x);
                int _entityY = floor(_entityList[e]->position.y);
                if (_entityX == i && _entityY == j) {
                    DrawCharVisual(_entityX, _entityY, _entityList[e]->charVisual);
                }
            }
        }
    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}

void Buffer::DrawBox(int coordX, int coordY) {
    //Ici on dessine une boite de la taille d'une case de grille
    for (int k = 0; k < screenGridRatio * 2; k++) {
        for (int l = 0; l < screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = coordX * screenGridRatio * 2 + k;
            int charCoordY = coordY * screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            buffer[charCoordY][charCoordX].Char.AsciiChar = 'X';
            buffer[charCoordY][charCoordX].Attributes = 0x0A;
        }
    }
}

void Buffer::DrawCharVisual(int _x, int _y, char _charVisual) {
    for (int k = 0; k < screenGridRatio * 2; k++) {
        for (int l = 0; l < screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = _x * screenGridRatio * 2 + k;
            int charCoordY = _y * screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            buffer[charCoordY][charCoordX].Char.UnicodeChar = 0x2580;
            buffer[charCoordY][charCoordX].Attributes = 0x0003 + 0x0020;
        }
    }
}

void Buffer::DrawBackground(int _x, int _y, char _charVisual) {
    for (int k = 0; k < screenGridRatio * 2; k++) {
        for (int l = 0; l < screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = _x * screenGridRatio * 2 + k;
            int charCoordY = _y * screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            buffer[charCoordY][charCoordX].Char.UnicodeChar = 0x2580;
            buffer[charCoordY][charCoordX].Attributes = 0x0000 + 0x0000;
        }
    }
}