#pragma once
#include <iostream>
#include <windows.h>
#include "Entity.h";

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
    Player(int _x, int _y, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK) : Entity(_x, _y) {     // Constructor       
        leftVK = _leftVK;
        rightVK = _rightVK;
        upVK = _upVK;
        downVK = _downVK;
        orientation = 0;
    }

     void Update() {
        if (GetAsyncKeyState(downVK)) {
           x += SPEED;
        }
        if (GetAsyncKeyState(upVK)) {
            x -= SPEED;
        }
        if (GetAsyncKeyState(rightVK)) {
            y += SPEED;
        }
        if (GetAsyncKeyState(leftVK)) {
            y -= SPEED;
        }
     }
};

