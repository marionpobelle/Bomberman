#include "Transform.h"

Transform::Transform(float _x, float _y, std::string _spriteName)
{
    position.x = _x;
    position.y = _y;
    spriteName = _spriteName;
}

void Transform::Update(std::vector<Transform*>& _entityList, Grid& grid) //constructor
{

}
