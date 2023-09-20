#pragma once
#include <iostream>

class Entity
{
public:
    float x;
    float y;

    Entity(float _x, float _y) {     // Constructor
        x = _x;
        y = _y;
    }

    virtual void Update() {

    }
};
