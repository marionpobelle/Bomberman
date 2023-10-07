#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Buffer.h"
#include "Transform.h"
#include "WallTypes.h"

using namespace std;

Buffer::Buffer(int _maxLineSize, int _screenGridRatio) : maxSize(_maxLineSize), screenGridRatio(_screenGridRatio)
{

}

void Buffer::UpdateConsole(Grid grid, std::vector<Transform*>& _entityList) {
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
            //DrawBox(coordX, coordY);
            FillTabWalls(coordX, coordY);
        }
        else {
            //DrawBackground(coordX, coordY, 'A');
            FillTabGround(coordX, coordY);
        }
    }
    //On peint le buffer avec les caracteres
    PaintCharactersInBuffer(charsTab, grid);
    //On peint les entites
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {   
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

/*void Buffer::DrawBox(int coordX, int coordY) {
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
}*/

void Buffer::FillTabWalls(int coordX, int coordY) {
    //Ici on dessine une boite de la taille d'une case de grille
    for (int k = 0; k < screenGridRatio * 2; k++) {
        for (int l = 0; l < screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = coordX * screenGridRatio * 2 + k;
            int charCoordY = coordY * screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            charsTab[charCoordY][charCoordX] = 1;
        }
    }
}

void Buffer::FillTabGround(int coordX, int coordY) {
    //Ici on dessine une boite de la taille d'une case de grille
    for (int k = 0; k < screenGridRatio * 2; k++) {
        for (int l = 0; l < screenGridRatio; l++) {
            //avoir les coordonn�es 
            int charCoordX = coordX * screenGridRatio * 2 + k;
            int charCoordY = coordY * screenGridRatio + l;
            //ajout de char dans le buffer, a modifier plus tard pour l'adapter en fonction du character � afficher
            charsTab[charCoordY][charCoordX] = 0;
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

/*void Buffer::DrawBackground(int _x, int _y, char _charVisual) {
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
}*/

void Buffer::PaintCharactersInBuffer(int charsTab[SCREEN_HEIGHT][SCREEN_WIDTH], Grid grid) {
    //On commence par peindre les bords du tableau charsTab
    for (int j = 0; j < (grid.gameGridWidth * 2 * GRID_RATIO); j++) {
        charsTab[0][j] = 1;
        buffer[0][j].Char.UnicodeChar = 0x2588;
        buffer[0][j].Attributes = 0x0B;

        charsTab[(grid.gameGridHeight * GRID_RATIO)-1][j] = 1;
        buffer[(grid.gameGridHeight * GRID_RATIO)-1][j].Char.UnicodeChar = 0x2588;
        buffer[(grid.gameGridHeight * GRID_RATIO)-1][j].Attributes = 0x0B;
    }
    for (int i = 0; i < grid.gameGridHeight * GRID_RATIO; i++) {
        charsTab[i][0] = 1;
        buffer[i][0].Char.UnicodeChar = 0x2588;
        buffer[i][0].Attributes = 0x0B;

        charsTab[i][(grid.gameGridWidth * 2 * GRID_RATIO)-1] = 1;
        buffer[i][(grid.gameGridWidth * 2 * GRID_RATIO)-1].Char.UnicodeChar = 0x2588;
        buffer[i][(grid.gameGridWidth * 2 * GRID_RATIO)-1].Attributes = 0x0B;
    }
    //Pour chaque caractère dans le tableau charsTab (qui a la meme taille que le buffer),
    //on regarde si c'est un mur (1) ou un sol (0)
    for (int i = 1; i < SCREEN_HEIGHT-1; i++) {
        for (int j = 1; j < SCREEN_WIDTH-1; j++) {
            //Si case contient un mur
            if (charsTab[i][j] == 1) {
                //Si c'est un mur on check ses voisins pour savoir a quoi il ressemble
                string neighborsType = "";
                neighborsType += charsTab[i - 1][j];
                neighborsType += charsTab[i][j + 1];
                neighborsType += charsTab[i + 1][j];
                neighborsType += charsTab[i][j - 1];
                //On converti la string obtenue en int pour aller check dans les sets
                int neighborsTypeInt = (neighborsType[1] * 2 * 2 * 2) | (neighborsType[2] * 2 * 2) | (neighborsType[3] * 2) | (neighborsType[0]);
                //On check dans quel set le int se trouve
                string wallTypeName = "";
                int wallTypeIndex = 30;
                for (int k = 0; k < WallTypes::GetWallTypes().wallTypesArray.size(); k++) {
                    //On recupere l'index du set qui contient la bonne valeur
                    if (WallTypes::GetWallTypes().wallTypesArray[k].count(neighborsTypeInt)) {
                        wallTypeIndex = k;
                        break;
                    }

                }
                wallTypeName = WallTypes::GetWallTypes().wallTypeNamesArray[wallTypeIndex];
                //On check dans la Map le code ASCII correspondant
                int asciiCode = WallTypes::GetWallTypes().characterCodes.find(wallTypeName)->second;
                //On le donne au Buffer
                buffer[i][j].Char.UnicodeChar = asciiCode;
                buffer[i][j].Attributes = 0x0B;
                //Si c'est un sol on peint du vide ou du sol si on veut un truc particulier
                //ou on fait rien
            }
            else {
                buffer[i][j].Char.UnicodeChar = 0x2580;
                buffer[i][j].Attributes = 0x0000 + 0x0000;
            }
        }
    }
}