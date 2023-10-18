#pragma once
#include "Transform.h"
#include "NYTimer.h"
#include "Explosion.h"
#include "AudioEngine.h"

/*
===============================================================================
The Bomb class represents the object bomb.
===============================================================================
*/
class Bomb : public Transform
{
public:
	/*
    ====================
    Bomb()
	    Constructor for the Bomb object.
        @param _x : Int the coordinate on the X axis.
        @param _y : Int the coordinate on the Y axis.
        @param _spriteName : String keyword that's used to find the matching sprite.
    ====================
    */
    Bomb( float _x, float _y, std::string _spriteName );

    /*
    ====================
    Update()
        Called every frame.
        @param _entityList : Container which includes the list of all the entities present in the game.
        @param _grid : Reference to the grid.
    ====================
    */
    void Update( std::vector<Transform*> &_entityList, Grid &_grid );

    /*
    ====================
    Explode()
        Called when Bomb is supposed to explode. Explosion behavior.
        @param _entityList : Container which includes the list of all the entities present in the game.
        @param _grid : Reference to the grid.
    ====================
    */
    void Explode( std::vector<Transform*> &_entityList, Grid &_grid );

private:
    float timer;
};

