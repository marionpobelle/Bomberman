#pragma once
#include "Transform.h"
#include "NYTimer.h"
#include "Explosion.h"

class Bomb : public Transform
{
public:
    Bomb(float _x, float _y, std::string _spriteName);
    void Update(std::vector<Transform*>& _entityList, Grid& grid);
    void Explode(std::vector<Transform*>& _entityList, Grid& grid);
    void ExplodeTowards(std::vector<Transform*>& _entityList, Grid& grid, int _x, int _y, int _orientation);
    void Draw(Buffer& _buffer, int _x, int _y);

private:
    float timer;
};

