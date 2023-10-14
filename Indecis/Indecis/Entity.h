#pragma once
#include "Transform.h";

class Entity : public Transform
{

public:
    Entity(float _x, float _y, std::string _sprite);
    virtual void Update(std::vector<Transform*>& _entityList, Grid& grid);
    virtual void ExplosionReaction(std::vector<Transform*>& _entityList);
};

