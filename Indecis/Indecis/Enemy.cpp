#include "Enemy.h"

float Enemy::SPEED = .01;

Enemy::Enemy(float _x, float _y, char _charVisual) //constructor
	: Entity(_x, _y, _charVisual)
{}

void Enemy::Update(std::vector<Transform*>& _entityList, Grid& _grid) {
	//Basic Movement
	//Get random grid position as objectif with Grid::GetRandomCoordinates()
	int objectifPosition = _grid.GetRandomFloorCoordinates();
	//NEED PATHFINDING
}
	



	//Player in sight Movement
	// Check at each increase/decrease if we see the player
	//Bomb check