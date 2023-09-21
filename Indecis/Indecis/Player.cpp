#include "Player.h"
float Player::SPEED = .05;

Player::Player(float _x, float _y, char _charVisual, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK) //constructor
    : Entity(_x, _y), leftVK(_leftVK), rightVK(_rightVK), upVK(_upVK), downVK(_downVK), bombVK(_bombVK), orientation(0)
{}


void Player::Update(std::vector<Entity*>& _entityList, Grid& grid) {
    if (GetAsyncKeyState(downVK)) {
        int nextStep = grid.GetGridCoordinates(floor(x)+1, floor(y));
        if (grid.grid[nextStep] != 1) {
        	position.y += (SPEED * NYTimer::deltaTime);
            orientation = 0;
        }
        else {
            std::cout << "collision" << std::endl;
        }
    }
    if (GetAsyncKeyState(upVK)) {
        int nextStep = grid.GetGridCoordinates(floor(x) - 1, floor(y));
        if (grid.grid[nextStep] != 1) {
        	position.y -= (SPEED * NYTimer::deltaTime);
            orientation = 2;
        }
    }
    if (GetAsyncKeyState(rightVK)) {
        int nextStep = grid.GetGridCoordinates(floor(x), floor(y) + 1);
        if (grid.grid[nextStep] != 1) {
        	position.x += (SPEED * NYTimer::deltaTime);
        	orientation = 1;
        }

    }
    if (GetAsyncKeyState(leftVK)) {
        int nextStep = grid.GetGridCoordinates(floor(x), floor(y) - 1);
        if (grid.grid[nextStep] != 1) {
        	position.x -= (SPEED * NYTimer::deltaTime);
        	orientation = 3;
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
    _entityList.push_back(new Bomb(bombX, bombY, 'B'));
}