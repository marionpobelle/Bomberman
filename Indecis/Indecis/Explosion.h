#pragma once
#include "Transform.h";
#include "NYTimer.h"

class Explosion : public Transform
{
public:
	Explosion(float _x, float _y, std::string _spriteName);
	void Update(std::vector<Transform*>& _entityList, Grid& grid);
	void ExplodeTowards(std::vector<Transform*>& _entityList, Grid& _grid, int _x, int _y, int _orientation);

private:
	float timer;
};

