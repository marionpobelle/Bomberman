#include <set>
#include <map>
#include <string>
#include "WallTypes.h"
WallTypes* WallTypes::wallTypesPointer = nullptr;

WallTypes::WallTypes() {
	WALL_CORNER_UP_RIGHT.insert(BAS|GAUCHE);
	WALL_CORNER_UP_LEFT.insert(DROITE|BAS);

	WALL_HORIZONTAL.insert(DROITE|BAS|GAUCHE);
	WALL_HORIZONTAL.insert(HAUT|DROITE|GAUCHE);

	WALL_CORNER_BOTTOM_RIGHT.insert(HAUT|GAUCHE);
	WALL_CORNER_BOTTOM_LEFT.insert(HAUT|DROITE);

	WALL_VERTICAL.insert(HAUT|BAS|GAUCHE);
	WALL_VERTICAL.insert(HAUT|DROITE|BAS);

	WALL_FULL.insert(HAUT|DROITE|BAS|GAUCHE);

	WALL_TRASH.insert(GAUCHE);
	WALL_TRASH.insert(BAS);
	WALL_TRASH.insert(DROITE);
	WALL_TRASH.insert(DROITE|GAUCHE);
	WALL_TRASH.insert(HAUT);
	WALL_TRASH.insert(HAUT|BAS);

	//Array incluant les sets contenant les codes
	wallTypesArray[0] = WALL_CORNER_UP_RIGHT;
	wallTypesArray[1] = WALL_CORNER_UP_LEFT;
	wallTypesArray[2] = WALL_HORIZONTAL;
	wallTypesArray[3] = WALL_VERTICAL;
	wallTypesArray[4] = WALL_CORNER_BOTTOM_RIGHT;
	wallTypesArray[5] = WALL_CORNER_BOTTOM_LEFT;
	wallTypesArray[6] = WALL_FULL;
	wallTypesArray[7] = WALL_TRASH;

	//Array incluant les noms des sets
	wallTypeNamesArray[0] = "WALL_CORNER_UP_RIGHT";
	wallTypeNamesArray[1] = "WALL_CORNER_UP_LEFT";
	wallTypeNamesArray[2] = "WALL_HORIZONTAL";
	wallTypeNamesArray[3] = "WALL_VERTICAL";
	wallTypeNamesArray[4] = "WALL_CORNER_BOTTOM_RIGHT";
	wallTypeNamesArray[5] = "WALL_CORNER_BOTTOM_LEFT";
	wallTypeNamesArray[6] = "WALL_FULL";
	wallTypeNamesArray[7] = "WALL_TRASH";

	//Insert
	characterCodes.insert(std::make_pair("WALL_CORNER_UP_RIGHT", 191));
	characterCodes.insert(std::make_pair("WALL_CORNER_UP_LEFT", 218));
	characterCodes.insert(std::make_pair("WALL_HORIZONTAL", 196));
	characterCodes.insert(std::make_pair("WALL_VERTICAL", 124));
	characterCodes.insert(std::make_pair("WALL_CORNER_BOTTOM_RIGHT", 217));
	characterCodes.insert(std::make_pair("WALL_CORNER_BOTTOM_LEFT", 192));
	characterCodes.insert(std::make_pair("WALL_FULL", 35)); //changer si on veut vide 32
	characterCodes.insert(std::make_pair("WALL_TRASH", 36));

}

//TU FAIS GetWallTypes().leNomDuTruc et ca te le donne INSANE
WallTypes WallTypes::GetWallTypes() {
	if (wallTypesPointer == nullptr) {
		wallTypesPointer = new WallTypes();
	}
	return *wallTypesPointer;
}