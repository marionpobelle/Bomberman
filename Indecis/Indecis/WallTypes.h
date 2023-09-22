#pragma once

class WallTypes
{
	private:
		std::set<int> WALL_CORNER_UP_RIGHT;
		std::set<int> WALL_CORNER_UP_LEFT;
		std::set<int> WALL_HORIZONTAL;
		std::set<int> WALL_CORNER_BOTTOM_RIGHT;
		std::set<int> WALL_CORNER_BOTTOM_LEFT;
		std::set<int> WALL_VERTICAL;
		std::set<int> WALL_FULL;
		std::set<int> WALL_TRASH;

		std::set<int>wallTypesArray[8];
		std::string wallTypeNamesArray[8];
		std::map<std::string, int> characterCodes;

		static WallTypes* wallTypesPointer;
		WallTypes();
		

	public:

		enum WALLS {
			HAUT = 1,
			DROITE = 2,
			BAS = 4,
			GAUCHE = 8
		};

		static WallTypes GetWallTypes();
		
};

