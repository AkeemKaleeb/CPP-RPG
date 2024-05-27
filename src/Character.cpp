#include "Character.hpp"
#include "Inventory.hpp"

Character::Character(std::string name, int health, int attack, int defense, int magic)
    : name(name), health(health), attack(attack), defense(defense), magic(magic), equippedArmor(nullptr), equippedWeapon(nullptr) {}

void Character::doAttack(Character& target) {
    int damage = this->attack;
    if(equippedWeapon != nullptr) {
        damage += equippedWeapon->attackMod;
    }
    target.takeDamage(damage);
}

void Character::takeDamage(int damage) {
    int reducedDamage = damage - (this->defense + (equippedArmor ? equippedArmor->defenseMod : 0));
    if(reducedDamage > 0) {
        health -= reducedDamage;
    }
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getAttack() const {
    return attack;
}

int Character::getMagic() const {
    return magic;
}

void Character::equipArmor(const Item& armor) {
    equippedArmor = new Item(armor);
}

void Character::equipWeapon(const Item& weapon) {
    equippedWeapon = new Item(weapon);
}

void Character::addToInventory(const Item& item) {
    inventory.push_back(item);
}
