#pragma once
#include "Character.hpp"

class Enemy : public Character {
public:
    Enemy(std::string name, int health, int attack, int defense, int magic);
    virtual ~Enemy() = default;
};
