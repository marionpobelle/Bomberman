#pragma once
#include "Transform.h";

class Entity : public Transform
{

public:
    Entity(float _x, float _y, char _charVisual);
    virtual void Update(std::vector<Transform*>& _entityList, Grid& grid);

};

