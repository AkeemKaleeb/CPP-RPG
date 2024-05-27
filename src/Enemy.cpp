/* 
    Holds enemy attributes
    Defines enemt behavior and AI
*/

#include "Enemy.hpp"

Enemy::Enemy(std::string name, int health, int attack, int defense, int magic)
    : Character(name, health, attack, defense, magic) {}
