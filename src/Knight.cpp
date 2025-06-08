#include "Knight.h"
#include <iostream>

Knight::Knight()
    : Character(120, "Knight", "Sword Slash", "Shield Bash") {}

void Knight::simpleAttack(Character& opponent) {
    int damage = 10;
    std::cout << name << " strikes with Sword!\n";
    opponent.takeDamage(damage);
}

void Knight::specialAttack(Character& opponent) {
    int damage = 20;
    std::cout << name << " bashes with Shield!\n";
    opponent.takeDamage(damage);
}

void Knight::resetLifePoints() {
    lifePoints = 120;
}

Knight::~Knight() {}
