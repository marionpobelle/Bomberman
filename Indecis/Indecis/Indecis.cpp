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
Buffer buffer = Buffer( 10 );
Grid grid( 10, 10 );
int amountOfDummyWalls = 8;
UISystem uiSystem;

void Update() {
    for ( int i = 0; i < entityList.size(); i++ )
    {
        entityList[i]->Update( entityList, grid );
    }
    buffer.UpdateConsole( grid, entityList, uiSystem );
}

int main()
{
    ShowWindow( GetConsoleWindow(), SW_MAXIMIZE );
    float Size = 0.5;
    UIWindow* window = new UIWindow( 0.9f, 0.5f, 0.2f, 0.2f, 2 );
    window->SetTextHorAlignment( UIWindow::HoriAlignment::HMiddle );
    window->SetTextVerAlignment( UIWindow::VertAlignment::VMiddle );
    window->SetWindowHorAlignment( UIWindow::HoriAlignment::HMiddle );
    window->SetWindowVerAlignment( UIWindow::VertAlignment::VMiddle );
    window->maxCharByLines = 20;
    window->SetText( "YOOO qu'est-ce que tu fais �a va trkl tu t'emmerdes pas trop ?" );
    window->isOpened = true;


    uiSystem.UIWindows.push_back( window );

    grid.ReadAndAddFileToGrid( "maps/map.txt" );
    //For sound
    AudioEngine::Init();
    AudioEngine::PlayLoop("music\\AnAdventureintheFuture.ogg");

    //buffer.UpdateConsole(grid, entityList, uiSystem);
    NYTimer deltaTime = NYTimer();
    SpriteReader spriteReader = SpriteReader();
    buffer.DrawFixedMap( grid );
    entityList.push_back( new Player( 1, 1, "PLAYER", VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SHIFT ) );
    entityList.push_back( new Player( grid.gameGridWidth - 2, grid.gameGridHeight - 2, "PLAYER", 0x51, 0x44, 0x5A, 0x53, 0x45 ) );
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