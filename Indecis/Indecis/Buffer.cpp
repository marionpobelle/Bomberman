#include "Buffer.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

Buffer::Buffer(int screenWidth, int screenHeight) {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { screenWidth,screenHeight };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, screenWidth - 1, screenHeight - 1 };

    CHAR_INFO buffer[screenWidth];

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);

    buffer[7][10].Char.AsciiChar = 'H';
    buffer[7][10].Attributes = 0x0E;
    buffer[7][11].Char.AsciiChar = 'i';
    buffer[7][11].Attributes = 0x0B;
    buffer[7][12].Char.AsciiChar = '!';
    buffer[7][12].Attributes = 0x0A;

    buffer[6][1].Char.AsciiChar = '1';
    buffer[6][1].Attributes = 0x0B;
    buffer[6][2].Char.AsciiChar = '2';
    buffer[6][2].Attributes = 0x0B;
    buffer[5][1].Char.AsciiChar = '3';
    buffer[5][1].Attributes = 0x0B;
    buffer[5][2].Char.AsciiChar = 218;
    buffer[5][2].Attributes = 0x0B;

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}
