#include "Player.h"
float Player::SPEED = 0.1;

Player::Player(int _x, int _y, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK) //constructor
    : Entity(_x, _y), leftVK(_leftVK), rightVK(_rightVK), upVK(_upVK), downVK(_downVK), bombVK(_bombVK)
{}


void Player::Update(std::vector<Entity*>& _entityList) {
    if (GetAsyncKeyState(downVK)) {
        x += SPEED;
        orientation = 1;
    }
    if (GetAsyncKeyState(upVK)) {
        x -= SPEED;
        orientation = 3;
    }
    if (GetAsyncKeyState(rightVK)) {
        y += SPEED;
        orientation = 0;
    }
    if (GetAsyncKeyState(leftVK)) {
        y -= SPEED;
        orientation = 2;
    }
    if (GetAsyncKeyState(bombVK)) {
        PlantBomb(_entityList);
    }
    if (bombCooldown > 0) bombCooldown -= .1;
}

void Player::PlantBomb(std::vector<Entity*>& _entityList) {
    if (bombCooldown > 0) return;
    bombCooldown = 3.0;
    int bombX = x;
    int bombY = y;
    switch (orientation)
    {
    case 0:
        bombY = floor(y) + 2;
        break;
    case 1:
        bombX = floor(x) + 1;
        break;
    case 2:
        bombY = floor(y) - 2;
        break;
    case 3:
        bombX = floor(x) - 1;
        break;
    default:
        break;
    }
    _entityList.push_back(new Entity(bombX, bombY));
}


void Player::Draw(Buffer &_buffer, int _x, int _y){
    _buffer.buffer[_x][_y] .Attributes = 0x0001 + 0x0020;
    _buffer.buffer[_x][_y].Char.UnicodeChar = 0x2580;
    if (_y >= 1) {
        _buffer.buffer[_x][_y - 1].Attributes = 0x0001 + 0x0020;
        _buffer.buffer[_x][_y - 1].Char.UnicodeChar = 0x2580;
    }
}