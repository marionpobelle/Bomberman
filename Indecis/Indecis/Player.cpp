#include "Player.h"
float Player::SPEED = .01;

Player::Player(float _x, float _y, char _charVisual, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK) //constructor
    : Entity(_x, _y, _charVisual), leftVK(_leftVK), rightVK(_rightVK), upVK(_upVK), downVK(_downVK), bombVK(_bombVK), orientation(0)
{}


void Player::Update(std::vector<Entity*> &_entityList, Grid &_grid) {
    if (GetAsyncKeyState(downVK)) {
        int nextStep = _grid.GetGridCoordinates(floor(position.x), floor(position.y) + 1);
        if (_grid.grid[nextStep] != 1) {
        	position.y += (SPEED * NYTimer::deltaTime);
            orientation = 0;
        } else {
            position.y = floor(position.y);
        }
    }
    if (GetAsyncKeyState(upVK)) {
        int nextStep = _grid.GetGridCoordinates(floor(position.x), floor(position.y) - 1);
        if (_grid.grid[nextStep] != 1) {
        	position.y -= (SPEED * NYTimer::deltaTime);
            orientation = 2;
        } else {
            position.y = floor(position.y);
        }
    }
    if (GetAsyncKeyState(rightVK)) {
        int nextStep = _grid.GetGridCoordinates(floor(position.x) + 1, floor(position.y));
        if (_grid.grid[nextStep] != 1) {
        	position.x += (SPEED * NYTimer::deltaTime);
        	orientation = 1;
        } else {
            position.x = floor(position.x);
        }
    }
    if (GetAsyncKeyState(leftVK)) {
        int nextStep = _grid.GetGridCoordinates(floor(position.x) - 1, floor(position.y));
        if (_grid.grid[nextStep] != 1) {
        	position.x -= (SPEED * NYTimer::deltaTime);
        	orientation = 3;
        } else {
            position.x = floor(position.x);
        }
    }

    if (GetAsyncKeyState(bombVK)) {
        PlantBomb(_entityList);
    }

    if (bombCooldown > 0) bombCooldown -= 0.005 * NYTimer::deltaTime;
}

void Player::PlantBomb(std::vector<Entity*>& _entityList) {
    if (bombCooldown > 0) return;
    bombCooldown = 3.0;
    int bombX = position.x;
    int bombY = position.y;
    switch (orientation)
    {
    case 0:
        bombY = floor(position.y) + 1;
        break;
    case 1:
        bombX = floor(position.x) + 1;
        break;
    case 2:
        bombY = floor(position.y) - 1;
        break;
    case 3:
        bombX = floor(position.x) - 1;
        break;
    default:
        break;
    }
    _entityList.push_back(new Bomb(bombX, bombY, 'B'));
}