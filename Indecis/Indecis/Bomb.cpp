#include "Bomb.h"

Bomb::Bomb(float _x, float _y, char _charVisual) //constructor
    : Transform(_x, _y, _charVisual), timer(3000)
{}

void Bomb::Update(std::vector<Transform*>& _entityList, Grid& grid) {
    timer -= NYTimer::deltaTime;

    if (timer <= 0) {
        std::vector<Transform*>::iterator ptr;
        for (ptr = _entityList.begin(); ptr < _entityList.end(); ptr++) {
            if (*ptr == this) {
                _entityList.erase(ptr);
                break;
            }
        }
        delete this;
    }
}

void Bomb::Draw(Buffer& _buffer, int _x, int _y) {
    _buffer.buffer[_x][_y].Attributes = 0x0003 + 0x0020;
    _buffer.buffer[_x][_y].Char.UnicodeChar = 0x2580;
    if (_y >= 1) {
        _buffer.buffer[_x][_y - 1].Attributes = 0x0004 + 0x0020;
        _buffer.buffer[_x][_y - 1].Char.UnicodeChar = 0x2580;
    }
}