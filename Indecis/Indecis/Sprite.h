#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

/*
===============================================================================
The Sprite class characterize the visuals for game objects using the name of the file that contains the sprite and its values.
===============================================================================
*/
class Sprite
{

public:
	/*
	====================
	Sprite()
		Constructor for the Sprite object.
		@param _name : String that defines the name of the file that contains the sprite.
		@param _sprite : String value that's used to define the sprite.
	====================
	*/
	Sprite( std::string _name, std::string _sprite );
	std::string name;
	std::string sprite;
};

