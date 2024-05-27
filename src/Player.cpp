/* 
    Holds player attributes
    Manages player inventory and equipment
    Defines player actions
*/

#include "Player.hpp"
#include <iostream>

Player::Player(std::string name, int health, int attack, int defense, int magic)
    : Character(name, health, attack, defense, magic) {}

void Player::printStats() const {
    std::cout << "Name: " << name << '\n';
    std::cout << "Health: " << health << '\n';
    std::cout << "Attack: " << attack << '\n';
    std::cout << "Defense: " << defense << '\n';
    std::cout << "Magic: " << magic << '\n';
    std::cout << "Equipped Armor: " << (equippedArmor ? equippedArmor->name : "None") << '\n';
    std::cout << "Equipped Weapon: " << (equippedWeapon ? equippedWeapon->name : "None") << '\n';
}
