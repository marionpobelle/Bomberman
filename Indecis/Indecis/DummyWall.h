#pragma once
#include "Entity.h";
#include "Explosion.h";

/*
===============================================================================
The DummyWall class contains variables that characterize the destructible walls entities.
===============================================================================
*/
class DummyWall : public Entity
{

public:
	/*
	====================
	DummyWall()
		Constructor for the DummyWall object.
		@param _x : Float that represents the position on the X axis.
		@param _y : Float that represents the position on the Y axis.
		@param _spriteName : String that represents the name of the sprite for destructible walls.
	====================
	*/
    DummyWall(float _x, float _y, std::string _spriteName);

	/*
	====================
	ExplosionReaction()
		Execute a series of action when the object is hit by an explosion.
		@param entityList : Container whose values are the transforms of all the entities of the game.
	====================
	*/
    void ExplosionReaction(std::vector<Transform*>& _entityList);
};

