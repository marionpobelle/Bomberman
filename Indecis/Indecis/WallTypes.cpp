#include <set>
#include <map>
#include <string>
#include "WallTypes.h"
WallTypes* WallTypes::wallTypesPointer = nullptr;

WallTypes::WallTypes() {
	WALL_CORNER_UP_RIGHT.insert(BAS|GAUCHE);
	WALL_CORNER_UP_LEFT.insert(DROITE|BAS);

	//WALL_HORIZONTAL.insert(DROITE|BAS|GAUCHE);
	//WALL_HORIZONTAL.insert(HAUT|DROITE|GAUCHE);
	WALL_TOP.insert(HAUT|DROITE|GAUCHE);
	WALL_BOTTOM.insert(DROITE|BAS|GAUCHE);

	WALL_CORNER_BOTTOM_RIGHT.insert(HAUT|GAUCHE);
	WALL_CORNER_BOTTOM_LEFT.insert(HAUT|DROITE);

	//WALL_VERTICAL.insert(HAUT|BAS|GAUCHE);
	WALL_LEFT.insert(HAUT|BAS|GAUCHE);
	WALL_RIGHT.insert(HAUT|DROITE|BAS);
	//WALL_VERTICAL.insert(HAUT|DROITE|BAS);

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

	//wallTypesArray[2] = WALL_HORIZONTAL;
	wallTypesArray[2] = WALL_TOP;
	wallTypesArray[3] = WALL_BOTTOM;

	//wallTypesArray[3] = WALL_VERTICAL;
	wallTypesArray[4] = WALL_LEFT;
	wallTypesArray[5] = WALL_RIGHT;

	wallTypesArray[6] = WALL_CORNER_BOTTOM_RIGHT;
	wallTypesArray[7] = WALL_CORNER_BOTTOM_LEFT;

	wallTypesArray[8] = WALL_FULL;
	wallTypesArray[9] = WALL_TRASH;

	//Array incluant les noms des sets
	wallTypeNamesArray[0] = "WALL_CORNER_UP_RIGHT";
	wallTypeNamesArray[1] = "WALL_CORNER_UP_LEFT";
	//wallTypeNamesArray[2] = "WALL_HORIZONTAL";
	wallTypeNamesArray[2] = "WALL_TOP";
	wallTypeNamesArray[3] = "WALL_BOTTOM";
	//wallTypeNamesArray[3] = "WALL_VERTICAL";
	wallTypeNamesArray[4] = "WALL_LEFT";
	wallTypeNamesArray[5] = "WALL_RIGHT";
	wallTypeNamesArray[6] = "WALL_CORNER_BOTTOM_RIGHT";
	wallTypeNamesArray[7] = "WALL_CORNER_BOTTOM_LEFT";
	wallTypeNamesArray[8] = "WALL_FULL";
	wallTypeNamesArray[9] = "WALL_TRASH";

	//Insert
	characterCodes.insert(std::make_pair("WALL_CORNER_UP_RIGHT", 0x2588));
	characterCodes.insert(std::make_pair("WALL_CORNER_UP_LEFT", 0x2588));
	//characterCodes.insert(std::make_pair("WALL_HORIZONTAL", 196));
	characterCodes.insert(std::make_pair("WALL_TOP", 0x2588)); //Coherent : 0x2584
	characterCodes.insert(std::make_pair("WALL_BOTTOM", 0x2588)); //Coherent : 0x2580

	//characterCodes.insert(std::make_pair("WALL_VERTICAL", 0x259E));
	characterCodes.insert(std::make_pair("WALL_LEFT", 0x2588)); //Coherent : 0x258C
	characterCodes.insert(std::make_pair("WALL_RIGHT", 0x2588)); //Coherent : 0x2590

	characterCodes.insert(std::make_pair("WALL_CORNER_BOTTOM_RIGHT", 0x2588));
	characterCodes.insert(std::make_pair("WALL_CORNER_BOTTOM_LEFT", 0x2588));
	characterCodes.insert(std::make_pair("WALL_FULL", 0x2588)); //changer si on veut vide 32
	characterCodes.insert(std::make_pair("WALL_TRASH", 0x2591));

}

//TU FAIS GetWallTypes().leNomDuTruc et ca te le donne INSANE
WallTypes WallTypes::GetWallTypes() {
	if (wallTypesPointer == nullptr) {
		wallTypesPointer = new WallTypes();
	}
	return *wallTypesPointer;
}