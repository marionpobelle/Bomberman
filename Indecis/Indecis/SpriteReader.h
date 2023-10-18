#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sprite.h"
#include <algorithm>
#include <windows.h>

class Sprite;

/*
===============================================================================
The SpriteReader class characterize the methods allowing the use of Sprites.
===============================================================================
*/
class SpriteReader
{
public:
	/*
	====================
	SpriteReader()
		Constructor for the SpriteReader object.
	====================
	*/
    SpriteReader();

	/*
	====================
	ReadAndSaveSprite()
		Read a sprite value from a fie and add it to the sprite list for the game.
		@param fileName : String that defines the name of the file that contains the sprite.
	====================
	*/
    static void ReadAndSaveSprite( std::string fileName );

	/*
	====================
	CallSprite()
		Get a sprite from the sprite list of the game.
		@param spriteName : Name of the sprite to get from the sprite list.
		@return : String, the sprite we wanted to get.
	====================
	*/
    static std::string CallSprite( std::string spriteName );

	//Sprite list of the game.
    static std::vector<Sprite*> spriteList;
};

