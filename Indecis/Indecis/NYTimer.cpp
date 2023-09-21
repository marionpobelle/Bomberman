#include "NYTimer.h"
 LARGE_INTEGER NYTimer::lastUpdateTime;
 LONGLONG NYTimer::freq;
 float NYTimer::deltaTime;

NYTimer::NYTimer() { //constructor
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

void NYTimer::Start(void) {
	QueryPerformanceCounter(&lastUpdateTime);
}

float NYTimer::getElapsedSeconds(bool restart) {
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}

void NYTimer::deltaTimeCalcul() { //calcule à chaque frame la valeur de delta time dans l'update de Indecis.cpp
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);

	lastUpdateTime = timeNow;

	deltaTime = elapsed;
}

unsigned long NYTimer::getElapsedMs(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);
	return elapsed;
}
