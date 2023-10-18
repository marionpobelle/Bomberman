#include "AudioEngine.h"
#include <iostream>
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib")

using namespace irrklang;

bool AudioEngine::m_isInitialized;
ISoundEngine* AudioEngine::m_soundEngine;

void AudioEngine::Init() {
	if ( !m_isInitialized ) {
		m_soundEngine = createIrrKlangDevice();
		if ( !m_soundEngine ) {
		} else {
			m_isInitialized = true;
		}
	}
}

void AudioEngine::PlayOneShot( const char* path )
{
	if ( !m_isInitialized ) return;
	m_soundEngine->play2D( path, false );
	m_soundEngine->setSoundVolume(0.2);
}

void AudioEngine::PlayLoop( const char* path )
{
	if ( !m_isInitialized ) return;
	m_soundEngine->play2D( path, true );
	m_soundEngine->setSoundVolume( 0.2 );
}