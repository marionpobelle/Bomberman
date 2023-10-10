#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Definitions.h"
#include "Grid.h"
#include "Buffer.h"
#include "NYTimer.h"
#include "Transform.h"
#include "Player.h"
#include "WallTypes.h"
#include <io.h>
#include <fcntl.h>
#include "SpriteReader.h"

std::vector<Transform*> entityList;
Buffer buffer = Buffer(10, GRID_RATIO);
Grid grid(10, 10);

void Update() {
    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->Update(entityList, grid);
    }
    buffer.UpdateConsole(grid, entityList);
}

int main()
{
    grid.ReadAndAddFileToGrid("maps/map.txt");
    //buffer.UpdateConsole(grid, entityList);
    NYTimer deltaTime = NYTimer();
    SpriteReader spriteReader = SpriteReader();
    buffer.DrawFixedMap(grid);
    entityList.push_back(new Player(1, 1, 'P', VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SHIFT));
    entityList.push_back(new Player(grid.gameGridWidth - 2, grid.gameGridHeight - 2, 'P', 0x51, 0x44, 0x5A, 0x53, 0x45));

    while (true) {
        Update();
        NYTimer::deltaTimeCalcul();
    }
    int i = 0;
    std::cin >> i;
    return 0;
}