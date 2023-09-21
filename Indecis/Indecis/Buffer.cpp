#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>;
#include "Buffer.h"
#include "Entity.h"

using namespace std;

Buffer::Buffer(int _maxSize) : m_maxSize(_maxSize)
{

}

void Buffer::UpdateConsole(int Grid[], int size, std::vector<Entity*> &_entityList) {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
    dwBufferCoord, &rcRegion);

    //reading Grid toward buffer (temp will be changed later)
    for (int i = 0; i < size; ++i) {
        int height = (int)ceil(i / m_maxSize);
        buffer[height][i % m_maxSize].Char.AsciiChar = Grid[i];
    }

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

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}