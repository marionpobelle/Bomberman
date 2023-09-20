#pragma once

class Entity
{
public:
    float x;
    float y;

    Entity(float _x, float _y) {     // Constructor
        x = _x;
        y = _y;
    }

    void Update() {
        //std::cout << "yo" << std::endl;
    }
};
