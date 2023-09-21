#pragma once
#include <iostream>
#include <vector>
#include "Buffer.h"

class Buffer;

class Entity
{
public:
	struct Position {
		float x = 0;
		float y = 0;
	};
	Position position;

	char charVisual;
	std::string visual;

    Entity(float _x, float _y, char _charVisual);

    virtual void Update(std::vector<Entity*> &_entityList);

};
