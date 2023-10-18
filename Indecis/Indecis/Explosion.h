#pragma once
#include "Transform.h";
#include "NYTimer.h"
#include "Player.h"

/*
===============================================================================
The Explosion class characterize a bomb explosion: its animation and what it affects.
===============================================================================
*/
class Explosion : public Transform
{
public:
    /*
    ====================
    Explosion()
        Constructor for the Explosion object.
        @param _x : Int the coordinate on the X axis.
        @param _y : Int the coordinate on the Y axis.
        @param _spriteName : String keyword that's used to find the matching sprite.
    ====================
    */
	Explosion( float _x, float _y, std::string _spriteName );

	/*
	====================
	Update()
		Used to update the position of the entity on the game grid to display its effect and to erase entities that might be on its way.
		@param entityList : Container whose values are the transforms of all the entities of the game.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
	void Update( std::vector<Transform*>& _entityList, Grid& grid );

	/*
	====================
	ExplosionTowards_r()
		.
		@param entityList : Container whose values are the transforms of all the entities of the game.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
		@param _x : Int the coordinate on the X axis.
		@param _y : Int the coordinate on the Y axis.
		@param _orientation : Int the direction of the explosion.
		@param _currentCase : Int the current level of progression of the explosion.
	====================
	*/
	void ExplodeTowards_r( std::vector<Transform*>& _entityList, Grid& _grid, int _x, int _y, int _orientation, int _currentCase = 0 );

private:
	//Timer for the explosion animation.
	float timer;
};

