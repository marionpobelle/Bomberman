#pragma once
#include <windows.h>

class Buffer
{
public:
	Buffer(const int screenWidth, const int screenHeight);
	CHAR_INFO m_buffer[50][50];

private:


};

