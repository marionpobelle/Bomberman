#pragma once
#include <ik_ISoundEngine.h>

/*
===============================================================================
The AudioEngine class contains functions that allows sounds to be played, in loop
and over each over if necessary.
===============================================================================
*/
class AudioEngine
{
public:
	/*
	====================
	Init()
		Initialize an Audio engine so that sounds can be played.
	====================
	*/
	static void Init();

	/*
	====================
	PlayOneShot()
		Plays a sound once, over other sounds if anything else is playing.
		@param path : Pointer to the path the sound to play can be found.
	====================
	*/
	static void PlayOneShot(const char* path);

	/*
	====================
	PlayLoop()
		Plays a sound in loop.
		@param path : Pointer to the path the sound to play can be found.
	====================
	*/
	static void PlayLoop(const char* path);

private:
	static bool m_isInitialized;
	static irrklang::ISoundEngine* m_soundEngine;
};