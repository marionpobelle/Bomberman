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
        Explode(_entityList, grid);
        delete this;
    }
}

void Bomb::Explode(std::vector<Transform*>& _entityList, Grid& grid) {
    Explosion *_firstExplosion = new Explosion(position.x, position.y, 'E');
    _entityList.push_back(_firstExplosion);
    _firstExplosion->ExplodeTowards(_entityList, grid, position.x - 1, position.y, 3); //left
    _firstExplosion->ExplodeTowards(_entityList, grid, position.x + 1, position.y, 1); //right
    _firstExplosion->ExplodeTowards(_entityList, grid, position.x, position.y + 1, 0); //up
    _firstExplosion->ExplodeTowards(_entityList, grid, position.x, position.y - 1, 2); //down
}

void Bomb::Draw(Buffer& _buffer, int _x, int _y) {
    _buffer.buffer[_x][_y].Attributes = 0x0003 + 0x0020;
    _buffer.buffer[_x][_y].Char.UnicodeChar = 0x2580;
    if (_y >= 1) {
        _buffer.buffer[_x][_y - 1].Attributes = 0x0004 + 0x0020;
        _buffer.buffer[_x][_y - 1].Char.UnicodeChar = 0x2580;
    }
}