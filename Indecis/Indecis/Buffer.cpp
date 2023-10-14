#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm> 
#include "Grid.h"
#include "UIWindow.h"
#include "UISystem.h"
#include "Buffer.h"
#include "Transform.h"
#include "WallTypes.h"

using namespace std;

Buffer::Buffer(int _maxLineSize, int _screenGridRatio) : maxSize(_maxLineSize), screenGridRatio(_screenGridRatio)
{

}

void Buffer::UpdateConsole(Grid grid, std::vector<Transform*>& _entityList, UISystem uiSystem) {
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
    PaintCharactersInBuffer(charsTab);

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
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            if (i == 0 || i == SCREEN_HEIGHT - 1 || j == 0 || j == SCREEN_WIDTH - 1) {
                buffer[i][j].Char.UnicodeChar = 0x0000;
                buffer[i][j].Attributes = 0x0007 + 0x0000;
                buffer[i][j].Char.AsciiChar = '*';
            }
        }
    }
    //calls the function that will draw the game UI 
    DrawUI(uiSystem);

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

void Buffer::PaintCharactersInBuffer(int charsTab[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    //Pour chaque caractère dans le tableau charsTab (qui a la meme taille que le buffer),
    //on regarde si c'est un mur (1) ou un sol (0)
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            //Si case contient un mur
            if (charsTab[i][j] == 1) {
                //Si c'est un mur on check ses voisins pour savoir a quoi il ressemble
                string neighborsType = "";
                neighborsType += charsTab[i - 1][j];
                neighborsType += charsTab[i][j + 1];
                neighborsType += charsTab[i + 1][j];
                neighborsType += charsTab[i][j - 1];
                //On converti la string obtenue en int pour aller check dans les sets
                int neighborsTypeInt = (neighborsType[0] * 2 * 2 * 2) + (neighborsType[1] * 2 * 2) + (neighborsType[2] * 2) + (neighborsType[3]);
                //On check dans quel set le int se trouve
                string wallTypeName = "";
                int wallTypeIndex = 7;
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
                buffer[i][j].Char.AsciiChar = asciiCode;
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

void Buffer::DrawUI(UISystem uiSystem) {
    // first we get the UISystem's windows and then iterate through them
    std::vector<UIWindow*>::iterator iterator = uiSystem.UIWindows.begin();
    std::vector<UIWindow*>::iterator end = uiSystem.UIWindows.end();

    for (;iterator != end; ++iterator)
    {
        UIWindow& window = **iterator;
        if (window.isOpened) {
            DrawWindow(window);
        }
    }
}

void Buffer::DrawWindow(UIWindow& window) {
    int xWindowCharSize = window.size.xScale * SCREEN_WIDTH + window.size.xPx;
    int yWindowCharSize = window.size.yScale * SCREEN_HEIGHT + window.size.yPx;
    std::string charTable = window.DisplayWindow();

    for (int i = 0; i <  yWindowCharSize; i++)
    {
        for (int j = 0; j < xWindowCharSize; j++)
        {
            
            int charCoordX = window.position.xScale * SCREEN_WIDTH + window.position.xPx + j;
            charCoordX = charCoordX - window.xWindowSub * xWindowCharSize;
            charCoordX = std::fmaxf(xWindowCharSize/2, std::fminf(charCoordX, SCREEN_WIDTH - xWindowCharSize/2));
            int charCoordY = window.position.yScale * SCREEN_HEIGHT + window.position.yPx + i;
            charCoordY = charCoordY - window.yWindowSub * yWindowCharSize;
            charCoordY = std::fmaxf(yWindowCharSize / 2, std::fminf(charCoordY, SCREEN_HEIGHT - yWindowCharSize / 2));
            buffer[charCoordY][charCoordX].Char.UnicodeChar = 0x0000;
            buffer[charCoordY][charCoordX].Attributes = 0x0007 + 0x0000;
            if (i * xWindowCharSize + j < charTable.size()) {
                buffer[charCoordY][charCoordX].Char.AsciiChar = charTable[i * xWindowCharSize + j];
            }
            if (i == 0 || i == yWindowCharSize -1 || j == 0 || j == xWindowCharSize-1){
                buffer[charCoordY][charCoordX].Char.AsciiChar = '*';
            }
        }
    }
}