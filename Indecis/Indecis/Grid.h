#pragma once
#include "Grid.h";

class Transform;

/*
===============================================================================
The Grid class represents the game grid.
===============================================================================
*/
class Grid
{
public:
	//Pointer towards the elements of the grid.
	int* grid;
	//Game fgrid size as a 1 dimensional table.
	int gameGridSize;
	//Game grid width.
	const int gameGridWidth = 10;
	//Game grid height.
	const int gameGridHeight = 10;

	/*
	====================
	Grid()
		Constructor for the Grid object.
		@param gameGridWidth : Width for the game grid.
		@param gameGridHeight : Height for the game grid.
	====================
	*/
	Grid( int _gameGridWidth, int _gameGridHeight )	;

	/*
	====================
	ReadAndAddFileToGrid()
		Read a text file that contains a series of 0 (ground) and 1 (walls) and transfer its structure into the game grid.
		@param fileName : String that contains the name of the file to read.
	====================
	*/
	void ReadAndAddFileToGrid( std::string _fileName );

	/*
	====================
	GetGridCoordinates()
		Read a text file that contains a series of 0 (ground) and 1 (walls) and transfer its structure into the game grid.
		@param _x : Int the coordinate on the X axis.
		@param _y : Int the coordinate on the Y axis.
		@return : Int, the coordinates (x,y) in the grid represented as a 1 dimensional table.
	====================
	*/
	int GetGridCoordinates( int _x, int _y );

	/*
	====================
	GetRandomFloorCoordinatesRefs()
		Change the value of the coordinate parameters x and y to random coordinates within the ground tiles of the grid.
		@param _x : Float a coordinate on the X axis.
		@param _y : Float a coordinate on the Y axis.
		@param _entityList : Container which includes the list of all the entities present in the game.
	====================
	*/
	void GetRandomFloorCoordinatesRefs( float &_x, float &_y, std::vector<Transform*> &_entityList );

	/*
	====================
	HasTransformHere()
		Checks if there is an entity at the grid coordinates specified by the parameters x, y.
		@param _x : Int the coordinate on the X axis.
		@param _y : Int the coordinate on the Y axis.
		@param _entityList : Container which includes the list of all the entities present in the game.
		@return : Boolean, true if there is an entity at these coordinates, false otherwise.
	====================
	*/
	bool HasTransformHere( int _x, int _y, std::vector<Transform*> &_entityList );

	/*
	====================
	HasCollision()
		Checks if there is an entity or a wall at the grid coordinates specified by the parameters x, y.
		@param _x : Int the coordinate on the X axis.
		@param _y : Int the coordinate on the Y axis.
		@param _entityList : Container which includes the list of all the entities present in the game.
		@return : Boolean, true if there is an entity or a wall at these coordinates, false otherwise.
	====================
	*/
	bool HasCollision( int _x, int _y, std::vector<Transform*> &_entityList );

	/*
	====================
	GetTransformHere()
		Get the transform of an entity at the grid coordinates specified by the parameters x, y if there is one.
		@param _x : Int the coordinate on the X axis.
		@param _y : Int the coordinate on the Y axis.
		@param _entityList : Container which includes the list of all the entities present in the game.
		@return : Pointer towards a Transform, the transform of an entity if there is one at these coordinates, the null pointer otherwise.
	====================
	*/
	Transform* GetTransformHere( int _x, int _y, std::vector<Transform*> &_entityList );
};

