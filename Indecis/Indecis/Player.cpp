#include "Player.h"
float Player::SPEED = 0.1;

Player::Player(int _x, int _y, char _charVisual, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK) //constructor
    : Entity(_x, _y, _charVisual), leftVK(_leftVK), rightVK(_rightVK), upVK(_upVK), downVK(_downVK), bombVK(_bombVK)
{}


void Player::Update(std::vector<Entity*>& _entityList) {
    if (GetAsyncKeyState(downVK)) {
        position.y += SPEED;
        orientation = 0;
    }
    if (GetAsyncKeyState(upVK)) {
        position.y -= SPEED;
        orientation = 2;
    }
    if (GetAsyncKeyState(rightVK)) {
        
        position.x += SPEED;
        orientation = 1;
    }
    if (GetAsyncKeyState(leftVK)) {
        
        position.x -= SPEED;
        orientation = 3;
    }
    if (GetAsyncKeyState(bombVK)) {
        PlantBomb(_entityList);
    }
    if (bombCooldown > 0) bombCooldown -= .1;
}

void Player::PlantBomb(std::vector<Entity*>& _entityList) {
    if (bombCooldown > 0) return;
    bombCooldown = 3.0;
    int bombX = position.x;
    int bombY = position.y;
    switch (orientation)
    {
    case 0:
        bombY = floor(position.y) + 2;
        break;
    case 1:
        bombX = floor(position.x) + 1;
        break;
    case 2:
        bombY = floor(position.y) - 2;
        break;
    case 3:
        bombX = floor(position.x) - 1;
        break;
    default:
        break;
    }
    _entityList.push_back(new Entity(bombX, bombY, 'B'));
}