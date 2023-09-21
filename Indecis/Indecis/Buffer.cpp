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

    //CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

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
                if (round(_entityList[e]->x) == i && round(_entityList[e]->y) == j) {
                    _entityList[e]->Draw(*this);
                    //buffer[i][j].Attributes = 0x2580;
                    //buffer[i][j].Char.AsciiChar = 0x2580;
                    //if (i >= 1 && j >= 1) {
                    //    buffer[i][j - 1].Attributes = 0x2580;
                    //    buffer[i][j - 1].Char.AsciiChar = 0x2580;
                    //}

                }

            }
        }
    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}