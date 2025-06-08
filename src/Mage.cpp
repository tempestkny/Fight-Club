#include "Mage.h"
#include <iostream>

Mage::Mage()
    : Character(80, "Mage", "Fireball", "Arcane Surge") {}

void Mage::simpleAttack(Character& opponent) {
    int damage = 15;
    std::cout << name << " casts Fireball!\n";
    opponent.takeDamage(damage);
}

void Mage::specialAttack(Character& opponent) {
    int damage = 25;
    std::cout << name << " uses Arcane Surge!\n";
    opponent.takeDamage(damage);
}

void Mage::resetLifePoints() {
    lifePoints = 80;
}


Mage::~Mage() {}
