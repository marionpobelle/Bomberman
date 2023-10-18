#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Entity.h";
#include "Bomb.h"
#include "AudioEngine.h"

/*
===============================================================================
The Player class represents the object player and inherits the class Entity. 
It's where the input are detected for each player.
===============================================================================
*/
class Player : public Entity
{
public:
    int life = 4;
    int orientation;
    UCHAR leftVK;
    UCHAR rightVK;
    UCHAR upVK;
    UCHAR downVK;
    UCHAR bombVK;
    static float SPEED;
    float bombCooldown;
    UISystem::PlayerUI playerUI;

    /*
    ====================
    Player()
        Constructor for the Player object.
        @param _x : Int the coordinate on the X axis.
        @param _y : Int the coordinate on the Y axis.
        @param _spriteName : String keyword that's used to find the matching sprite.
        @param _leftVK : Key used by this player to got left.
        @param _rightVK : Key used by this player to got right.
        @param _upVK : Key used by this player to got up.
        @param _downVK : Key used by this player to got down.
        @param _bombVK : Key used by this player to plant bombs.
    ====================
    */
    Player( float _x, float _y, std::string _spriteName, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK );

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
    PlantBomb()
        Check if space is available to plant a bomb in front of the player and does so if possible.
        @param _entityList : Container which includes the list of all the entities present in the game.
        @param _grid : Reference to the grid.
    ====================
    */
    void PlantBomb( std::vector<Transform*> &_entityList, Grid &_grid );

    void Draw(Buffer &_buffer, int _x, int _y);

    /*
    ====================
    ExplosionReaction()
        Called when Player is caught by bomb explosion. 
        @param _entityList : Container which includes the list of all the entities present in the game.
    ====================
    */
    void ExplosionReaction( std::vector<Transform*>& _entityList );

private:
    /*
    ====================
    UpdateHearts()
        Updates the UI life indicator of the player.
    ====================
    */
    void UpdateHearts();

    float damageBlinkTimer = 0;
};

