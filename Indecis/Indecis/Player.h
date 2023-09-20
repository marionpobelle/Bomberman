#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
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

     void Update(std::vector<Entity*>& _entityList) {
        if (GetAsyncKeyState(downVK)) {
           x += SPEED;
           orientation = 1;
        }
        if (GetAsyncKeyState(upVK)) {
            x -= SPEED;
            orientation = 3;
        }
        if (GetAsyncKeyState(rightVK)) {
            y += SPEED;
            orientation = 0;
        }
        if (GetAsyncKeyState(leftVK)) {
            y -= SPEED;
            orientation = 2;
        }
        if (GetAsyncKeyState(VK_SHIFT)) {
            PlantBomb();
            int bombX = x;
            int bombY = y;
            switch (orientation)
            {
            case 0:
                bombY = round(y) + 1;
                break;
            case 1:
                bombX = round(x) + 2;
                break;
            case 2:
                bombY = round(y) - 1;
                break;
            case 3:
                bombX = round(x) - 1;
                break;
            default:
                break;
            }
            _entityList.push_back(new Entity(bombX, bombY));
        }
     }

     void PlantBomb() {

     }

     void Draw() {
         int _x = round(x);
         int _y = round(y);
         //Buffer::buffer[x] [y] .Attributes = 0x2580;
         //Buffer::buffer[x][y].Char.AsciiChar = 0x2580;
         //Buffer::buffer[x][y - 1].Attributes = 0x2580;
         //Buffer::buffer[x][y - 1].Char.AsciiChar = 0x2580;
     }
};

