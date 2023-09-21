#pragma once
#include "Entity.h"
#include "NYTimer.h"

class Bomb : public Entity
{
public:
    float timer;

    Bomb(float _x, float _y, char _charVisual);
    void Update(std::vector<Entity*>& _entityList, Grid& grid);
    void Draw(Buffer& _buffer, int _x, int _y);
};

