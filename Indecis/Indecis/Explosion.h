#pragma once
#include "Transform.h";
#include "NYTimer.h"
#include "Player.h"

class Explosion : public Transform
{
public:
	Explosion(float _x, float _y, std::string _spriteName);
	void Update(std::vector<Transform*>& _entityList, Grid& grid);
	void ExplodeTowards_r(std::vector<Transform*>& _entityList, Grid& _grid, int _x, int _y, int _orientation, int _currentCase = 0);

private:
	float timer;
};

