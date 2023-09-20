#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Entity.h";
#include "Buffer.h";

class Player : public Entity
{
public:
    int orientation;
    UCHAR leftVK;
    UCHAR rightVK;
    UCHAR upVK;
    UCHAR downVK;
    static float SPEED;

public:
    Player(int _x, int _y, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK);

    void Update(std::vector<Entity*>& _entityList);

    void PlantBomb(std::vector<Entity*>& _entityList);

    void Draw(Buffer buffer);
};

