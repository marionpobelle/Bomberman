#pragma once
#include <iostream>
#include <vector>
#include "Buffer.h"

class Buffer;

class Entity
{
public:
    float x;
    float y;

    Entity(float _x, float _y);

    virtual void Update(std::vector<Entity*> &_entityList, Grid& grid);

    virtual void Draw(Buffer& _buffer, int _x, int _y);
};
