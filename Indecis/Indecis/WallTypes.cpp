#include <set>
#include <map>
#include <string>
#include "WallTypes.h"

WallTypes* WallTypes::wallTypesPointer = nullptr;

WallTypes::WallTypes() {
	WALL_T_BOTTOM.insert( HAUT | DROITE | GAUCHE ); //11
	WALL_T_UP.insert( DROITE | BAS | GAUCHE ); //14
	WALL_T_LEFT.insert( HAUT | BAS | GAUCHE ); //13
	WALL_T_RIGHT.insert( HAUT | DROITE | BAS ); //7

	WALL_CORNER_BOTTOM_LEFT.insert( BAS | GAUCHE ); //12
	WALL_CORNER_BOTTOM_RIGHT.insert( DROITE | BAS ); //6
	WALL_CORNER_UP_LEFT.insert( HAUT | GAUCHE ); //9
	WALL_CORNER_UP_RIGHT.insert( HAUT | DROITE ); //3

	WALL_END_RIGHT.insert( GAUCHE ); //8
	WALL_END_BOTTOM.insert( BAS ); //4
	WALL_END_LEFT.insert( DROITE ); //2
	WALL_END_TOP.insert( HAUT ); //1

	WALL_HORIZONTAL.insert( DROITE | GAUCHE ); //10
	WALL_VERTICAL.insert( HAUT | BAS ); //5
	WALL_FULL.insert( DROITE | HAUT | BAS | GAUCHE );
	WALL_ALONE.insert( 0 );

	//Array that contains all the set<int> defining each type of wall by binary codes.
	wallTypesArray[0] = WALL_CORNER_UP_RIGHT;
	wallTypesArray[1] = WALL_CORNER_UP_LEFT;

	wallTypesArray[2] = WALL_T_LEFT;
	wallTypesArray[3] = WALL_T_UP;
	wallTypesArray[4] = WALL_T_RIGHT;
	wallTypesArray[5] = WALL_T_BOTTOM;

	wallTypesArray[6] = WALL_CORNER_BOTTOM_RIGHT;
	wallTypesArray[7] = WALL_CORNER_BOTTOM_LEFT;

	wallTypesArray[8] = WALL_FULL;
	wallTypesArray[9] = WALL_ALONE;

	wallTypesArray[10] = WALL_HORIZONTAL;
	wallTypesArray[11] = WALL_VERTICAL;

	wallTypesArray[12] = WALL_END_BOTTOM;
	wallTypesArray[13] = WALL_END_TOP;
	wallTypesArray[14] = WALL_END_LEFT;
	wallTypesArray[15] = WALL_END_RIGHT;

	//Array that contains all the names of the wall types, sorted in the same order as in wallTypesArray.
	wallTypeNamesArray[0] = "WALL_CORNER_UP_RIGHT";
	wallTypeNamesArray[1] = "WALL_CORNER_UP_LEFT";

	wallTypeNamesArray[2] = "WALL_T_LEFT";
	wallTypeNamesArray[3] = "WALL_T_UP";

	wallTypeNamesArray[4] = "WALL_T_RIGHT";
	wallTypeNamesArray[5] = "WALL_T_BOTTOM";

	wallTypeNamesArray[6] = "WALL_CORNER_BOTTOM_RIGHT";
	wallTypeNamesArray[7] = "WALL_CORNER_BOTTOM_LEFT";

	wallTypeNamesArray[8] = "WALL_FULL";
	wallTypeNamesArray[9] = "WALL_ALONE";
	wallTypeNamesArray[10] = "WALL_HORIZONTAL";
	wallTypeNamesArray[11] = "WALL_VERTICAL";
	wallTypeNamesArray[12] = "WALL_END_BOTTOM";
	wallTypeNamesArray[13] = "WALL_END_TOP";
	wallTypeNamesArray[14] = "WALL_END_LEFT";
	wallTypeNamesArray[15] = "WALL_END_RIGHT";
}

WallTypes WallTypes::GetWallTypes() {
	if ( wallTypesPointer == nullptr ) {
		wallTypesPointer = new WallTypes();
	}
	return *wallTypesPointer;
}