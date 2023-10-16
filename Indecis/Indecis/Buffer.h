#pragma once
#include <windows.h>
#include <vector>
#include "Transform.h"
#include "Definitions.h"
#include "Grid.h"

class Transform;

/*
===============================================================================
The Buffer class contains variables that characterize the buffer and
functions used to paint characters on the Windows console.
===============================================================================
*/
class Buffer
{
public:
	//See CHAR_INFO online documentation.
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	//Maximum size of the buffer.
	int maxSize;

	/*
	====================
	Buffer()
		Constructor for the Buffer object.
		@param _maxLineSize : Maximum size of the buffer.
	====================
	*/
	Buffer( int _maxLineSize );

	/*
	====================
	UpdateConsole()
		Paint the background, entities, map and UI in the buffer to display in the Windows Console.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
		@param entityList : Container whose values are the transforms of all the entities of the game.
		@param uiSystem : UISystem which contains all UI elements to put in the buffer to display on the Windows Console.
	====================
	*/
	void UpdateConsole( Grid _grid, std::vector<Transform*>& _entityList, UISystem _uiSystem );
	
	/*
	====================
	DrawFixedMap()
		Draw the game map contained in grid in the buffer.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
	void DrawFixedMap( Grid _grid );

private:
	/*
	====================
	FillTabWalls()
		Draw the game map walls contained in grid at the coordX,coordY coordinates in the buffer.
		@param coordX : Integer representing the x coordinate on the game grid.
		@param coordY : Integer representing the y coordinate on the game grid.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
	void FillTabWalls( int coordX, int coordY, Grid& _grid );

	/*
	====================
	FillTabGround()
		Draw the game map ground everywhere in the buffer.
		@param coordX : Integer representing the x coordinate on the game grid.
		@param coordY : Integer representing the y coordinate on the game grid.
	====================
	*/
	void FillTabGround( int coordX, int coordY );

	/*
	====================
	DrawUI()
		Description Draws the UI elements as well as the UI window.
		@param uiSystem : UISystem which contains all UI elements to put in the buffer to display on the Windows Console.
	====================
	*/
	void DrawUI( UISystem _uiSystem );

	/*
	====================
	DrawWindow()
		Draws the UI window in the buffer to display on the Windows Console.
		@param window : UIWindow which represent the UI window to display on the Windows Console.
	====================
	*/
	void DrawWindow( UIWindow& window );

	/*
	====================
	PaintSpriteInBuffer()
		Description Paint the sprite of the entity at the coordinates coordX,coordY on the game grid in the buffer.
		@param coordX : Integer representing the x coordinate on the game grid.
		@param coordY : Integer representing the y coordinate on the game grid.
		@param sprite : Container whose value form the sprite of the element to paint.
		@param grid : Grid which contains the map for the game, made out of multiple buffer slots.
	====================
	*/
	void PaintSpriteInBuffer( int coordX, int coordY, std::string sprite, Grid& _grid );
};

