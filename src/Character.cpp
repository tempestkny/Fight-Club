#include "Character.h"
#include <iostream>
#include <string>

std::vector<Character*> Character::allCharacters;

Character::Character(int lifePoints, std::string name, std::string simpleAttackName, std::string specialAttackName)
    : lifePoints(lifePoints), name(name), simpleAttackName(simpleAttackName), specialAttackName(specialAttackName), wins(0), losses(0) {
        allCharacters.push_back(this);
    }

// getter
std::string Character::getName() const {return name; }
std::string Character::getSimpleAttackName() { return simpleAttackName; }
std::string Character::getSpecialAttackName() { return specialAttackName; }
int Character::getLifePoints() {return lifePoints; }
int Character::getWins() {return wins; }
int Character::getLosses() {return losses; }

// functions
void Character::takeDamage(int damage) {
    this->lifePoints -= damage;

    if (lifePoints < 0) {
        lifePoints = 0;
    }

    std::cout << name << " takes " << damage << " damage. Remaining HP: " << lifePoints << "\n";
}

void Character::simpleAttack(Character& opponent) {
    std::cout << name << " performs a simple attack on " << opponent.getName() << ".\n";
}

void Character::specialAttack(Character& opponent) {
    std::cout << name << " performs a special attack on " << opponent.getName() << ".\n";
}

void Character::incrementWins() {
    wins++;
}

void Character::incrementLosses() {
    losses++;
}

void Character::printAllCharacterStats() {
    std::cout << "\n=== Character Stats ===\n";
    for (Character* c : allCharacters) {
        std::cout << c->getName() << " - Wins: " << c->getWins() << ", Losses: " << c->getLosses() << "\n";
    }
    std::cout << "========================\n\n";
}

Character* Character::findCharacterByName(const std::string& name) {
    for (Character* c : allCharacters) {
        if (c->getName() == name) {
            return c;
        }
    }
    return nullptr;
}

Character::~Character() {}
