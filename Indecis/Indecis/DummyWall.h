#pragma once
#include "Entity.h";
#include "Explosion.h";

class DummyWall : public Entity
{

public:
    DummyWall(float _x, float _y, std::string _spriteName);
    void ExplosionReaction(std::vector<Transform*>& _entityList);
};

