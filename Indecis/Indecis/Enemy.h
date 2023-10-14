#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Entity.h"
#include "Buffer.h";
#include "NYTimer.h"

class Enemy : public Entity
{
public:
	static float SPEED;

public:
	Enemy(float _x, float _y, char _charVisual);

	void Update(std::vector<Transform*>& _entityList, Grid& grid);

	void Draw(Buffer& _buffer, int _x, int _y);

};

