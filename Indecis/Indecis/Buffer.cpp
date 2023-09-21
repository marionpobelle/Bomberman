#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>;
#include "Grid.h"
#include "Buffer.h"
#include "Entity.h"

using namespace std;

Buffer::Buffer(int maxLineSize, int screenGridRatio) : m_maxSize(maxLineSize), m_screenGridRatio(screenGridRatio)
{

}

void Buffer::UpdateConsole(Grid grid, std::vector<Entity*>& _entityList) {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
    dwBufferCoord, &rcRegion);

    
    

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {   
            buffer[i][j].Attributes = 0x2577;
            for (int e = 0; e < _entityList.size(); e++)
            {
                int _entityX = floor(_entityList[e]->x);
                int _entityY = floor(_entityList[e]->y);
                if (_entityX == i && _entityY == j) {
                    _entityList[e]->Draw(*this, _entityX, _entityY);
                }
            }
        }
    }

    //Lecture de la grid vers le buffer
    for (int i = 0; i < grid.m_gameGridSize; ++i) {
        int coordY = (int)ceil(i / m_maxSize);
        int coordX = i % m_maxSize;
        if (grid.grid[i] == 1) {
            DrawBox(coordX, coordY);
        }
    }


    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}


void Buffer::DrawBox(int coordX, int coordY) {
    //Ici on dessine une boite de la taille d'une case de grille
    for (int k = 0; k < m_screenGridRatio * 2; k++) {
        for (int l = 0; l < m_screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = coordX * m_screenGridRatio * 2 + k;
            int CharCoordY = coordY * m_screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            buffer[CharCoordY][charCoordX].Char.AsciiChar = 'X';
            buffer[CharCoordY][charCoordX].Attributes = 0x0A;
        }
    }
}