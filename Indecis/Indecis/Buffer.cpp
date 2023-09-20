#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>;
#include "Buffer.h"
#include "Entity.h"

using namespace std;

Buffer::Buffer(int maxLineSize) {
    m_maxSize = maxLineSize;
}

void Buffer::UpdateConsole(int Grid[], int size, std::vector<Entity*> _entityList) {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    ////reading Grid toward buffer (temp will be changed later)
    ////for (int i = 0; i < size; ++i) {
    ////    int height = (int)ceil(i / Buffer::m_maxSize);
    ////    Buffer::buffer[height][i % Buffer::m_maxSize].Char.AsciiChar = Grid[i];
    ////}

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
    dwBufferCoord, &rcRegion);

    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {
            buffer[i][j].Attributes = 0x2577;
            for (int e = 0; e < _entityList.size(); e++)
            {
                if (round(_entityList[e]->x) == i && round(_entityList[e]->y) == j) {
                    buffer[i][j].Attributes = 0x2580;
                    buffer[i][j].Char.AsciiChar = 'i';
                }

            }
        }
    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}