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

		std::set<int> WALL_TOP;
		std::set<int> WALL_BOTTOM;

		std::set<int> WALL_CORNER_BOTTOM_RIGHT;
		std::set<int> WALL_CORNER_BOTTOM_LEFT;

		std::set<int> WALL_LEFT;
		std::set<int> WALL_RIGHT;

		std::set<int> WALL_FULL;
		std::set<int> WALL_TRASH;

		std::array<std::set<int>,10> wallTypesArray;
		std::array<std::string,10> wallTypeNamesArray;
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

