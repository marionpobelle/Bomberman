#pragma once
#include "Transform.h";

/*
===============================================================================
The Entity class characterize game objects that have a position, a sprite and
that react to explosions (damage).
===============================================================================
*/
class Entity : public Transform
{

public:
	/*
	====================
	Entity()
		Constructor for the Entity object.
		@param _x : Float that represents the position on the X axis.
		@param _y : Float that represents the position on the Y axis.
		@param _sprite : String keyword that's used to find the matching sprite.
	====================
	*/
    Entity( float _x, float _y, std::string _sprite );

	/*
	====================
	Update()
		Used to update the position of the entity on the game grid.
		@param entityList : Container whose values are the transforms of all the entities of the game.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
    virtual void Update( std::vector<Transform*>& _entityList, Grid& grid );

	/*
	====================
	ExplosionReaction()
		Execute a series of action when the entity is hit by an explosion.
		@param entityList : Container whose values are the transforms of all the entities of the game.
	====================
	*/
    virtual void ExplosionReaction( std::vector<Transform*>& _entityList );
};

