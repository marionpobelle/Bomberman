#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sprite.h"
#include <algorithm>
#include <windows.h>

class Sprite;

class SpriteReader
{
public:
    SpriteReader();
    static void ReadAndSaveSprite(std::string fileName);
    static std::string CallSprite(std::string spriteName);
    static std::vector<Sprite*> spriteList;
};

