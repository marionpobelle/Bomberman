#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Definitions.h"
#include "Grid.h"
#include "UIWindow.h"
#include "UISystem.h"
#include "Buffer.h"
#include "NYTimer.h"
#include "Transform.h"
#include "Player.h"
#include "DummyWall.h"
#include "WallTypes.h"
#include <io.h>
#include <fcntl.h>
#include "SpriteReader.h"
#include "AudioEngine.h"

std::vector<Transform*> entityList;
Buffer buffer = Buffer(10);
Grid grid(10, 10);
UISystem uiSystem = UISystem::GetUISystem(0.4f, 0.2f, 7);
bool uiHasToUpdate = false;
int amountOfDummyWalls = 8;

void Update() {
    for ( int i = 0; i < entityList.size(); i++ )
    {
        entityList[i]->Update( entityList, grid );
    }
    uiSystem.UpdateUIInput();
    buffer.UpdateConsole(grid, entityList, uiSystem);
    if (uiSystem.mainMenu->isOpened) {
        uiHasToUpdate = true;
    }
    else if (uiHasToUpdate) {
        buffer.DrawFixedMap(grid);
        uiHasToUpdate = false;
    }
}

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    buffer.xGameWindowPosition = SCREEN_WIDTH / 2 - 10 * GRID_RATIO;
    buffer.yGameWindowPosition = SCREEN_HEIGHT / 2 - 10 * GRID_RATIO/2;
    grid.ReadAndAddFileToGrid("maps/map.txt");
    //For sound
    AudioEngine::Init();
    AudioEngine::PlayLoop("music\\AnAdventureintheFuture.ogg");

    //buffer.UpdateConsole(grid, entityList, uiSystem);
    NYTimer deltaTime = NYTimer();
    SpriteReader spriteReader = SpriteReader();
    buffer.DrawFixedMap(grid);
    Player* player1 = new Player(1, 1, "PLAYER", VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SHIFT);
    Player* player2 = new Player(grid.gameGridWidth - 2, grid.gameGridHeight - 2, "PLAYERGREEN", 0x51, 0x44, 0x5A, 0x53, 0x45);

    UISystem::PlayerUI player1UI = uiSystem.GetPlayerUI(0);
    UISystem::PlayerUI player2UI = uiSystem.GetPlayerUI(1);
    player1->playerUI = player1UI;
    player2->playerUI = player2UI;
    entityList.push_back(player1);
    entityList.push_back(player2);

    float xDummy;
    float yDummy;
    for ( int i = 0; i < amountOfDummyWalls; i++ ) {
        grid.GetRandomFloorCoordinatesRefs( xDummy, yDummy, entityList );
        entityList.push_back(new DummyWall( xDummy, yDummy, "WALL_DUMMY" ) );
    }
    while ( true ) {
        Update();
        NYTimer::deltaTimeCalcul();
    }
    int i = 0;
    std::cin >> i;
    return 0;
}