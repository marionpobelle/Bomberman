#pragma once
#include "Entity.h"
#include "NYTimer.h"

class Bomb : public Entity
{
public:
    float timer;

    Bomb(float _x, float _y);
    void Update(std::vector<Entity*>& _entityList);
    void Draw(Buffer& _buffer, int _x, int _y);
};

