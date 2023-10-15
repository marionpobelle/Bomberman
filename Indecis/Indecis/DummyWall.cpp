#include "DummyWall.h"

DummyWall::DummyWall(float _x, float _y, std::string _spriteName) //constructor
    : Entity(_x, _y, _spriteName)
{}

void DummyWall::ExplosionReaction(std::vector<Transform*>& _entityList) {
    std::vector<Transform*>::iterator ptr;
    for (ptr = _entityList.begin(); ptr < _entityList.end(); ptr++) {
        if (*ptr == this) {
            _entityList.erase(ptr);
            break;
        }
    }
    delete this;
}