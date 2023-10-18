#include <iostream>
#include <string>
#include <vector>
#include "SpriteReader.h"

std::vector<Sprite*> SpriteReader::spriteList;

SpriteReader::SpriteReader() { //constructor

    //Load all references in specific folder and assign them a name
    std::string path = "sprites";
    for (const auto& file : std::filesystem::directory_iterator(path)) {
        ReadAndSaveSprite(file.path().string());
    }
}

void SpriteReader::ReadAndSaveSprite(std::string fileName) {
    //Recuperer le contenu du fichier, regarde quel type d'objet c'est et affiche le char
    //dans le buffer en consequence
    std::ifstream input;
    input.open(fileName);
    int tileCompositionMinSize = 3;

    std::stringstream strStream;
    strStream << input.rdbuf(); //read the file
    std::string value = strStream.str(); //str holds the content of the file
    value.erase(std::remove(value.begin(), value.end(), '\n'), value.cend());

    input.close();

    spriteList.push_back(new Sprite(fileName, value));
}

std::string SpriteReader::CallSprite(std::string spriteName) {
    std::string returnValue = " ";
    for (size_t i = 0; i < SpriteReader::spriteList.size(); i++)
    {
        std::string path = "sprites\\" + spriteName + ".txt";
        if (SpriteReader::spriteList[i]->name == path) {
            //std::cout << SpriteReader::spriteList[i]->name << std::endl;
            returnValue = SpriteReader::spriteList[i]->sprite;
            //std::cout << returnValue << std::endl;
        }
    }
    return returnValue;
}

