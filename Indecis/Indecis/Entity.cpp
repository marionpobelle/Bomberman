#include "Entity.h"

Entity::Entity(float _x, float _y) : x(_x), y(_y)
{}

void Entity::Update(std::vector<Entity*>& _entityList, Grid& grid) //constructor
{

}

void Entity::Draw(Buffer &_buffer, int _x, int _y) {
    _buffer.buffer[_x][_y].Attributes = 0x0003 + 0x0020;
    _buffer.buffer[_x][_y].Char.UnicodeChar = 0x2580;
    if (_y >= 1) {
        _buffer.buffer[_x][_y - 1].Attributes = 0x0004 + 0x0020;
        _buffer.buffer[_x][_y - 1].Char.UnicodeChar = 0x2580;
    }
}