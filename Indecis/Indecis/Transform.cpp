#include "Transform.h"

Transform::Transform(float _x, float _y, char _charVisual)
{
    position.x = _x;
    position.y = _y;
    charVisual = _charVisual;
}

void Transform::Update(std::vector<Transform*>& _entityList, Grid& grid) //constructor
{

}
