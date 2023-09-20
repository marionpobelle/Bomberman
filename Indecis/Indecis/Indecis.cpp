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

void Update() {
    for (size_t i = 0; i < entityList.size(); i++)
    {
        entityList[i]->Update();
    }
    Buffer::UpdateConsole(grid, 100, entityList);
}

int main()
{
    //Buffer buffer = Buffer(3);

    entityList.push_back(new Player(10, 10, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN));

    while (true) {
        Update();
    }
    return 0;
}