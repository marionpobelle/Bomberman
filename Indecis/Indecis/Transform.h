#pragma once
#include <iostream>
#include <vector>
#include "Buffer.h"

class Buffer;

class Transform
{
public:
	struct Position {
		float x = 0;
		float y = 0;
	};
	Position position;

	char charVisual;
	std::string visual;

    Transform(float _x, float _y, char _charVisual);

    virtual void Update(std::vector<Transform*> &_entityList, Grid& grid);
};
