#pragma once
#include <string>

class Item {
public:
    std::string name;
    int attackMod;
    int defenseMod;
    int magicMod;

    Item(std::string name, int attackMod, int defenseMod, int magicMod)
        : name(name), attackMod(attackMod), defenseMod(defenseMod), magicMod(magicMod) {}
};
