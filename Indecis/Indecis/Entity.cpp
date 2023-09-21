#include "Entity.h"

Entity::Entity(float _x, float _y) : x(_x), y(_y)
{}

void Entity::Update(std::vector<Entity*>& _entityList) //constructor
{

}

void Entity::Draw(Buffer &_buffer) {
    int _x = round(x);
    int _y = round(y);
    _buffer.buffer[_x][_y].Attributes = 0x2580;
    //_buffer.buffer[_x][_y].Char.AsciiChar = 0x2580;
    if (_y >= 1) {
        _buffer.buffer[_x][_y - 1].Attributes = 0x2580;
        //_buffer.buffer[_x][_y - 1].Char.AsciiChar = 0x2580;
    }
}