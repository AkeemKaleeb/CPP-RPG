#pragma once
#include "Character.hpp"

class Player : public Character {
public:
    Player(std::string name, int health, int attack, int defense, int magic);
    virtual ~Player() = default;

    void printStats() const;
};
