#pragma once
#include <array>
#include <set>
#include <map>

class WallTypes
{
	private:
		
		WallTypes();		

	public:

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

		std::array<std::set<int>,16> wallTypesArray;
		std::array<std::string,16> wallTypeNamesArray;
		std::map<std::string, int> characterCodes;

		static WallTypes* wallTypesPointer;

		enum WALLS {
			HAUT = 1,
			DROITE = 2,
			BAS = 4,
			GAUCHE = 8
		};

		static WallTypes GetWallTypes();
		
};

