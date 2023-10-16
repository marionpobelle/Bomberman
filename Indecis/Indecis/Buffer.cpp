#include "Definitions.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm> 
#include "Grid.h"
#include "UIWindow.h"
#include "UISystem.h"
#include "Buffer.h"
#include "Transform.h"
#include "WallTypes.h"
#include "SpriteReader.h"

using namespace std;

Buffer::Buffer( int _maxLineSize) : maxSize(_maxLineSize )
{

}

void Buffer::UpdateConsole( Grid _grid, std::vector<Transform*>& _entityList, UISystem _uiSystem ) {
    HANDLE hOutput = ( HANDLE )GetStdHandle( STD_OUTPUT_HANDLE );

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput( hOutput, ( CHAR_INFO* )buffer, dwBufferSize,
    dwBufferCoord, &rcRegion );

    //Painting the background
    for ( int i = 0; i < _grid.gameGridSize; ++i ) {
        int coordY = ( int )ceil( i / maxSize );
        int coordX = i % maxSize;
        if ( _grid.grid[i] != 1 ) {
            FillTabGround( coordX, coordY );
        }
    }
    //Painting the entities
    for ( int i = 0; i < SCREEN_WIDTH; i++ )
    {
        for ( int j = 0; j < SCREEN_HEIGHT; j++ )
        {   
            for ( int e = 0; e < _entityList.size(); e++ )
            {
                int _entityX = floor( _entityList[e]->position.x );
                int _entityY = floor( _entityList[e]->position.y );
                if ( _entityX == i && _entityY == j ) {
                    string _sprite = "";
                    if ( _entityList[e]->animFrame > 0 ) _sprite = _entityList[e]->spriteName + to_string( _entityList[e]->animFrame );
                    else _sprite = _entityList[e]->spriteName;
                    PaintSpriteInBuffer( _entityX, _entityY, SpriteReader::CallSprite( _sprite ), _grid );
                }
            }
        }
    }
    for ( int i = 0; i < SCREEN_HEIGHT; i++ )
    {
        for ( int j = 0; j < SCREEN_WIDTH; j++ )
        {
            if ( i == 0 || i == SCREEN_HEIGHT - 1 || j == 0 || j == SCREEN_WIDTH - 1 ) {
                buffer[i][j].Char.UnicodeChar = 0x0000;
                buffer[i][j].Attributes = 0x0007 + 0x0000;
                buffer[i][j].Char.AsciiChar = '*';
            }
        }
    }
    //Painting the game UI
    DrawUI( _uiSystem );
    WriteConsoleOutput( hOutput, ( CHAR_INFO* )buffer, dwBufferSize,
        dwBufferCoord, &rcRegion );
}

void Buffer::DrawFixedMap( Grid _grid ) {
    HANDLE hOutput = ( HANDLE )GetStdHandle( STD_OUTPUT_HANDLE );

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    ReadConsoleOutput( hOutput, ( CHAR_INFO* )buffer, dwBufferSize,
        dwBufferCoord, &rcRegion );

    //Reading from grid to buffer
    for ( int i = 0; i < _grid.gameGridSize; ++i ) {
        int coordY = ( int )ceil( i / maxSize );
        int coordX = i % maxSize;
        if ( _grid.grid[i] == 1 ) {
            FillTabWalls( coordX, coordY, _grid );
        }
    }

    WriteConsoleOutput( hOutput, ( CHAR_INFO* )buffer, dwBufferSize,
        dwBufferCoord, &rcRegion );
}

void Buffer::FillTabWalls( int coordX, int coordY, Grid& _grid ) {
    int neighborsType[4];
    if ( coordX == 0 ) neighborsType[0] = 0;
    else neighborsType[0] = _grid.grid[_grid.GetGridCoordinates( coordX - 1, coordY )];
    if ( coordY == _grid.gameGridHeight - 1 ) neighborsType[1] = 0;
    else neighborsType[1] = _grid.grid[_grid.GetGridCoordinates( coordX, coordY + 1 )];
    if ( coordX == _grid.gameGridWidth - 1 ) neighborsType[2] = 0;
    else neighborsType[2] = _grid.grid[_grid.GetGridCoordinates( coordX + 1, coordY )];
    if (coordY == 0) neighborsType[3] = 0;
    else neighborsType[3] = _grid.grid[_grid.GetGridCoordinates( coordX, coordY - 1 )];
    int neighborsTypeInt = ( neighborsType[0] * 2 * 2 * 2 ) + ( neighborsType[1] ) + ( neighborsType[2] * 2 ) + ( neighborsType[3] * 2 * 2 );
    string wallTypeName = "";
    int wallTypeIndex = 30;
    for ( int k = 0; k < WallTypes::GetWallTypes().wallTypesArray.size(); k++ ) {
        //We get the index of the set that holds the right value
        if ( WallTypes::GetWallTypes().wallTypesArray[k].count( neighborsTypeInt ) ) {
            wallTypeIndex = k;
            break;
        }
    }
    if ( wallTypeIndex != 30 ) wallTypeName = WallTypes::GetWallTypes().wallTypeNamesArray[wallTypeIndex];
    string sprite = SpriteReader::CallSprite( wallTypeName );
    PaintSpriteInBuffer( coordX, coordY, sprite, _grid );

}

void Buffer::PaintSpriteInBuffer( int coordX, int coordY, string sprite, Grid& _grid ) {
    int width = GRID_RATIO * 2;
    int height = GRID_RATIO;
    for ( int k = 0; k < width; k++ ) {
        for ( int l = 0; l < height; l++ ) {
            //We get the coordinates
            int charCoordX = coordX * GRID_RATIO * 2 + k;
            int charCoordY = coordY * GRID_RATIO + l;
            buffer[charCoordY][charCoordX].Char.UnicodeChar = 0x2580;
            if ( sprite.size() > width * height ) { 
                //We interpret each number as colors for the backgorund and foreground
                string text = "0x00" + string( 1, sprite[k + width + ( l * 2 * width )] ) + string( 1, sprite[k + ( l * 2 * width )] );
                WORD word = static_cast<WORD>( std::stoul( text, nullptr, 16 ) );
                buffer[charCoordY][charCoordX].Attributes = word;
            }
        }
    }
}

void Buffer::FillTabGround( int coordX, int coordY ) {
    //We draw a box that is the size of one grid slot.
    for ( int k = 0; k < GRID_RATIO * 2; k++ ) {
        for ( int l = 0; l < GRID_RATIO; l++ ) {
            //We get the coordinates
            int charCoordX = coordX * GRID_RATIO * 2 + k;
            int charCoordY = coordY * GRID_RATIO + l;
            buffer[charCoordY][charCoordX].Attributes = 0x0000;
        }
    }
}

void Buffer::DrawUI( UISystem _uiSystem ) {
    //We get the UISystem's windows and then iterate through them
    std::vector<UIWindow*>::iterator iterator = _uiSystem.UIWindows.begin();
    std::vector<UIWindow*>::iterator end = _uiSystem.UIWindows.end();

    for ( ;iterator != end; ++iterator )
    {
        UIWindow& window = **iterator;
        if ( window.isOpened ) {
            DrawWindow( window );
        }
    }
}

void Buffer::DrawWindow( UIWindow& window ) {
    int xWindowCharSize = window.size.xScale * SCREEN_WIDTH + window.size.xPx;
    int yWindowCharSize = window.size.yScale * SCREEN_HEIGHT + window.size.yPx;
    std::string charTable = window.DisplayWindow();

    for ( int i = 0; i < yWindowCharSize; i++ )
    {
        for ( int j = 0; j < xWindowCharSize; j++ )
        {
            
            int charCoordX = window.position.xScale * SCREEN_WIDTH + window.position.xPx + j;
            charCoordX = charCoordX - window.xWindowSub * xWindowCharSize;
            charCoordX = std::fmaxf( xWindowCharSize/2, std::fminf( charCoordX, SCREEN_WIDTH - xWindowCharSize/2 ) );
            int charCoordY = window.position.yScale * SCREEN_HEIGHT + window.position.yPx + i;
            charCoordY = charCoordY - window.yWindowSub * yWindowCharSize;
            charCoordY = std::fmaxf( yWindowCharSize / 2, std::fminf( charCoordY, SCREEN_HEIGHT - yWindowCharSize / 2 ) );
            buffer[charCoordY][charCoordX].Char.UnicodeChar = 0x0000;
            buffer[charCoordY][charCoordX].Attributes = 0x0007 + 0x0000;
            if ( i * xWindowCharSize + j < charTable.size() ) {
                buffer[charCoordY][charCoordX].Char.AsciiChar = charTable[i * xWindowCharSize + j];
            }
            if ( i == 0 || i == yWindowCharSize -1 || j == 0 || j == xWindowCharSize-1 ){
                buffer[charCoordY][charCoordX].Char.AsciiChar = '*';
            }
        }
    }
}