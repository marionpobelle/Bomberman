#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Definitions.h"
#include "Grid.h"
#include "Transform.h"

Grid::Grid( int _gameGridWidth, int _gameGridHeight ) : gameGridWidth( _gameGridWidth ), gameGridHeight( _gameGridHeight ), gameGridSize( 0 ) {
    gameGridSize = _gameGridWidth * _gameGridHeight;
    grid = new int[gameGridSize];
}

void Grid::ReadAndAddFileToGrid( std::string _fileName ) {
    std::ifstream input;
    input.open( _fileName );
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

int Grid::GetGridCoordinates( int _x, int _y ) {
    int coordinates = _y * gameGridWidth + _x;
    return coordinates;
}

void Grid::GetRandomFloorCoordinatesRefs( float &_x, float &_y, std::vector<Transform*> &_entityList ) {
    srand( time( 0 ) );
    do {
        _x = rand() % gameGridHeight;
        _y = rand() % gameGridWidth;
    } while ( HasCollision( _x, _y, _entityList ) );
}

Transform* Grid::HasTransformHere( int _x, int _y, std::vector<Transform*> &_entityList ) {
    for ( int i = 0; i < _entityList.size(); i++ )
    {
        if ( floor( _entityList[i]->position.x ) == _x && floor( _entityList[i]->position.y ) == _y ) {
            return _entityList[i];
        }
    }
    return nullptr;
}

bool Grid::HasCollision( int _x, int _y, std::vector<Transform*> &_entityList ) {
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


