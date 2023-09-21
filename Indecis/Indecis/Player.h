#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Entity.h";
#include "Buffer.h";
#include "Bomb.h"

class Player : public Entity
{
public:
    int orientation;
    UCHAR leftVK;
    UCHAR rightVK;
    UCHAR upVK;
    UCHAR downVK;
    UCHAR bombVK;
    static float SPEED;
    float bombCooldown;

public:
    Player(float _x, float _y, char _charVisual, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK);

    void Update(std::vector<Entity*> &_entityList);

    void PlantBomb(std::vector<Entity*> &_entityList);

    void Draw(Buffer &_buffer, int _x, int _y);
};

