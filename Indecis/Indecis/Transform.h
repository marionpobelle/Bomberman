#pragma once
#include <iostream>
#include <vector>
#include "UIWindow.h"
#include "UISystem.h"
#include "Buffer.h"

/*
===============================================================================
The Transform class characterize a position and a sprite.
===============================================================================
*/
class Transform
{
public:

	//Characterize a position on the X and Y axises.
	struct Position {
		float x = 0;
		float y = 0;
	};
	Position position;
	//Characterize a sprite by its name and framerate.
	std::string spriteName;
	int animFrame;

	/*
	====================
	Transform()
		Constructor for the Transform object.
		@param _x : Float that represents the position on the X axis.
		@param _y : Float that represents the position on the Y axis.
		@param _sprite : String keyword that's used to find the matching sprite.
	====================
	*/
    Transform( float _x, float _y, std::string _spriteName );

	/*
	====================
	Update()
		Used to update the position of the entity on the game grid.
		@param entityList : Container whose values are the transforms of all the entities of the game.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
    virtual void Update( std::vector<Transform*> &_entityList, Grid& grid );

	/*
	====================
	ExplosionReaction()
		Execute a series of action when the entity is hit by an explosion.
		@param entityList : Container whose values are the transforms of all the entities of the game.
	====================
	*/
	virtual void ExplosionReaction( std::vector<Transform*>& _entityList );
};
