#include "OwnCharacter.h"
#include <iostream>

OwnCharacter::OwnCharacter(std::string chosenName, std::string chosenBasic, std::string chosenSpecial) : Character(100, chosenName, chosenBasic, chosenSpecial) {}

void OwnCharacter::simpleAttack(Character& opponent) {
    int damage;

    if (simpleAttackName == "Quick Jab") {
        damage = 10;
    } if (simpleAttackName == "Power Kick") {
        damage = 11;
    } if (simpleAttackName == "Blade Slash") {
        damage = 12;
    } else if (simpleAttackName == "Elbow Smash") {
        damage = 13;
    }

    std::cout << name << " uses " << simpleAttackName << "!\n";
    opponent.takeDamage(damage);
}

void OwnCharacter::specialAttack(Character& opponent) {
    int damage;

    if (specialAttackName == "Meteor Fist") {
        damage = 25;
    } if (specialAttackName == "Shadow Strike") {
        damage = 20;
    } if (specialAttackName == "Chaos Burst") {
        damage = 22;
    } else if (specialAttackName == "Void Pulse") {
        damage = 50;
    }

    std::cout << name << " uses " << specialAttackName << "!\n";
    opponent.takeDamage(damage);
}

void OwnCharacter::resetLifePoints() {
    lifePoints = 100;
}


OwnCharacter::~OwnCharacter() {}
