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
	std::string spriteName;
	int animFrame;


    Transform(float _x, float _y, std::string _spriteName);

    virtual void Update(std::vector<Transform*> &_entityList, Grid& grid);
};
