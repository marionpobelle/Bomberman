#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Definitions.h"
#include "Grid.h"
#include "Transform.h"

Grid::Grid( int gameGridWidth, int gameGridHeight ) : gameGridWidth( gameGridWidth ), gameGridHeight( gameGridHeight ), gameGridSize( 0 ) {
    gameGridSize = gameGridWidth * gameGridHeight;
    grid = new int[gameGridSize];
}

void Grid::ReadAndAddFileToGrid( std::string fileName ) {
    std::ifstream input;
    input.open( fileName );
    char value;

    int Width = gameGridWidth;
    int Height = gameGridHeight;

    for ( int i = 0; i < gameGridHeight; i++ ) {
        for ( int j = 0; j < gameGridWidth; j++ ) {
            if ( input.fail() ) break;
            input >> value;
            int gridPos = ( i * gameGridWidth ) + j;
            grid[gridPos] = int( value - '0' );
        }
    }
    input.close();
}

int Grid::GetGridCoordinates( int x, int y ) {
    int coordinates = y * gameGridWidth + x;
    return coordinates;
}

void Grid::GetRandomFloorCoordinatesRefs( float& x, float& y, std::vector<Transform*>& _entityList ) {
    srand( time( 0 ) );
    do {
        x = rand() % gameGridHeight;
        y = rand() % gameGridWidth;
    } while ( HasCollision( x, y, _entityList ) );
}

Transform* Grid::HasTransformHere( int _x, int _y, std::vector<Transform*>& _entityList ) {
    for ( int i = 0; i < _entityList.size(); i++ )
    {
        if ( floor( _entityList[i]->position.x ) == _x && floor( _entityList[i]->position.y ) == _y ) {
            return _entityList[i];
        }
    }
    return nullptr;
}

bool Grid::HasCollision( int _x, int _y, std::vector<Transform*>& _entityList ) {
    int nextStep = GetGridCoordinates( _x, _y );
    if ( grid[nextStep] == 0 ) { 
        Transform* transf = HasTransformHere(_x, _y, _entityList);
        if ( transf )
            return true;
        else return false;
    }
    else
        return true;
}


