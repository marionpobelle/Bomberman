#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include "Buffer.h"
#include "NYTimer.h"
#include "Entity.h"
#include "Player.h"

std::vector<Entity*> entityList;
int grid[3];
Buffer buffer = Buffer(3);

void Update() {
    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->Update(entityList);
    }
    buffer.UpdateConsole(grid, 100, entityList);
}

int main()
{
    NYTimer deltaTime = NYTimer();
    entityList.push_back(new Player(10, 10, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SHIFT));
    entityList.push_back(new Player(10, 10, 0x51, 0x44, 0x5A, 0x53, 0x45));

    while (true) {
        Update();
        NYTimer::deltaTimeCalcul();
    }
    return 0;
}