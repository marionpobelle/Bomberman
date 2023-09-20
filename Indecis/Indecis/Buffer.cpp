#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "Buffer.h"

using namespace std;

Buffer::Buffer(int Grid[], int size, int MaxLineSize) {
    Buffer::m_maxSize = MaxLineSize;

    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput(hOutput, (CHAR_INFO*)Buffer::buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);

    //reading Grid toward buffer (temp will be changed later)
    int i = 0;
    for (i = 0; i < size; ++i) {
        int height = (int)ceil(i / Buffer::m_maxSize);
        Buffer::buffer[height][i % Buffer::m_maxSize].Char.AsciiChar = Grid[i];
    }


    WriteConsoleOutput(hOutput, (CHAR_INFO*)Buffer::buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}
