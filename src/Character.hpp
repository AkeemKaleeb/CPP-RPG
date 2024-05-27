#pragma once

#include "Item.hpp"
#include <string>
#include <vector>

class Character {
public:
    Character(std::string name, int health, int attack, int defense, int magic);
    virtual ~Character() = default;

    void doAttack(Character& target);
    void takeDamage(int damage);
    bool isAlive() const;

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getMagic() const;

    void equipArmor(const Item& armor);
    void equipWeapon(const Item& weapon);
    void addToInventory(const Item& item);

protected:
    std::string name;
    int health;
    int attack;
    int defense;
    int magic;

    Item* equippedArmor;
    Item* equippedWeapon;
    std::vector<Item> inventory;

};
