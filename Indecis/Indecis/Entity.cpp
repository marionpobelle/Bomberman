#include "Entity.h"

Entity::Entity(float _x, float _y, char _charVisual)
{
    position.x = _x;
    position.y = _y;
    charVisual = _charVisual;
}

void Entity::Update(std::vector<Entity*>& _entityList, Grid& grid) //constructor
{

}
