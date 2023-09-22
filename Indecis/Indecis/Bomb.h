#pragma once
#include "Transform.h"
#include "NYTimer.h"

class Bomb : public Transform
{
public:
    float timer;

    Bomb(float _x, float _y, char _charVisual);
    void Update(std::vector<Transform*>& _entityList, Grid& grid);
    void Draw(Buffer& _buffer, int _x, int _y);
};

