#pragma once
#include <array>
#include <set>
#include <map>

/*
===============================================================================
The WallTypes class contains all the variables that define what a wall looks like.
===============================================================================
*/
class WallTypes
{
	private:
		/*
		====================
		WallTypes()
			Constructor for the WallTypes object. Unused.
		====================
		*/
		WallTypes();		

	public:
		//All the set<int> below contains the binary codes that correspond to the type of wall that names the set.
		std::set<int> WALL_CORNER_UP_RIGHT;
		std::set<int> WALL_CORNER_UP_LEFT;

		std::set<int> WALL_T_LEFT;
		std::set<int> WALL_T_UP;

		std::set<int> WALL_CORNER_BOTTOM_RIGHT;
		std::set<int> WALL_CORNER_BOTTOM_LEFT;

		std::set<int> WALL_T_RIGHT;
		std::set<int> WALL_T_BOTTOM;

		std::set<int> WALL_FULL;
		std::set<int> WALL_ALONE;
		std::set<int> WALL_HORIZONTAL;
		std::set<int> WALL_VERTICAL;
		std::set<int> WALL_END_BOTTOM;
		std::set<int> WALL_END_TOP;
		std::set<int> WALL_END_LEFT;
		std::set<int> WALL_END_RIGHT;

		//An array that contains all the set<int> defining each type of wall by binary codes.
		std::array<std::set<int>,16> wallTypesArray;
		//An array that contains all the names of the wall types, sorted in the same order as in wallTypesArray.
		std::array<std::string,16> wallTypeNamesArray;

		//A pointer that that points toward the elements of the WallTypes class.
		static WallTypes* wallTypesPointer;

		//An enum that defines how much it adds to a wall binary code to have a wall on its top, right, bottom and left.
		enum WALLS_t {
			HAUT = 1,
			DROITE = 2,
			BAS = 4,
			GAUCHE = 8
		};

		/*
		====================
		GetWallTypes()
			Allows other files to access the elements of the WallTypes class.
			@return : WallTypes, the elements of the class WallTypes.
		====================
		*/
		static WallTypes GetWallTypes();
		
};

