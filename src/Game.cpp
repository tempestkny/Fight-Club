#include "Game.h"
#include "Character.h"
#include "Knight.h"
#include "Mage.h"
#include "OwnCharacter.h"
#include <vector>
#include <iostream>

#include "Game.h"
#include "Character.h"
#include "Knight.h"
#include "Mage.h"
#include "OwnCharacter.h"
#include <vector>
#include <iostream>

Game::Game()
{
    isGameOver = false;
    int input;

    std::vector<std::string> basicAttacks = {"Quick Jab", "Power Kick", "Blade Slash", "Elbow Smash"};
    std::vector<std::string> specialAttacks = {"Meteor Fist", "Shadow Strike", "Chaos Burst", "Void Pulse"};

    std::cout << "Choose a character or create your own!\n1. Knight\t2. Mage\t3. Own Character\n";
    std::cin >> input;

    switch (input) {
    case 1: {
        Character* existing = Character::findCharacterByName("Knight");
        player1 = existing ? existing : new Knight();
        break;
    }
    case 2: {
        Character* existing = Character::findCharacterByName("Mage");
        player1 = existing ? existing : new Mage();
        break;
    }
    case 3: {
        std::string chosenName;
        std::cout << "Your Name:\n";
        std::cin >> chosenName;

        Character* existing = Character::findCharacterByName(chosenName);
        if (existing) {
            player1 = existing;
            break;
        }

        std::cout << "Choose your basic attack:\n";
        for (size_t i = 0; i < basicAttacks.size(); ++i)
            std::cout << i + 1 << ". " << basicAttacks[i] << "\n";

        int basicChoice;
        do {
            std::cin >> basicChoice;
        } while (basicChoice < 1 || basicChoice > (int)basicAttacks.size());
        std::string chosenBasic = basicAttacks[basicChoice - 1];

        std::cout << "Choose your special attack:\n";
        for (size_t i = 0; i < specialAttacks.size(); ++i)
            std::cout << i + 1 << ". " << specialAttacks[i] << "\n";

        int specialChoice;
        do {
            std::cin >> specialChoice;
        } while (specialChoice < 1 || specialChoice > (int)specialAttacks.size());
        std::string chosenSpecial = specialAttacks[specialChoice - 1];

        player1 = new OwnCharacter(chosenName, chosenBasic, chosenSpecial);
        break;
    }
    default: {
        player1 = new Knight();
        break;
    }
    }

    std::cout << "Choose your opponent or create your own!\n1. Knight\t2. Mage\t3. Own Character\n";
    std::cin >> input;

    switch (input) {
    case 1: {
        Character* existing = Character::findCharacterByName("Knight");
        player2 = existing ? existing : new Knight();
        break;
    }
    case 2: {
        Character* existing = Character::findCharacterByName("Mage");
        player2 = existing ? existing : new Mage();
        break;
    }
    case 3: {
        std::string chosenName;
        std::cout << "Your Name:\n";
        std::cin >> chosenName;

        Character* existing = Character::findCharacterByName(chosenName);
        if (existing) {
            player2 = existing;
            break;
        }

        std::cout << "Choose your basic attack:\n";
        for (size_t i = 0; i < basicAttacks.size(); ++i)
            std::cout << i + 1 << ". " << basicAttacks[i] << "\n";

        int basicChoice;
        do {
            std::cin >> basicChoice;
        } while (basicChoice < 1 || basicChoice > (int)basicAttacks.size());
        std::string chosenBasic = basicAttacks[basicChoice - 1];

        std::cout << "Choose your special attack:\n";
        for (size_t i = 0; i < specialAttacks.size(); ++i)
            std::cout << i + 1 << ". " << specialAttacks[i] << "\n";

        int specialChoice;
        do {
            std::cin >> specialChoice;
        } while (specialChoice < 1 || specialChoice > (int)specialAttacks.size());
        std::string chosenSpecial = specialAttacks[specialChoice - 1];

        player2 = new OwnCharacter(chosenName, chosenBasic, chosenSpecial);
        break;
    }
    default: {
        player2 = new Mage();
        break;
    }
    }

    std::cout << "The Battle between " << player1->getName()
              << " and " << player2->getName() << " starts now!\n\n";
}


 void Game::run() {

    while (!isGameOver) {
        printPlayerStats();

        int input;
        std::cout << "Player 1: Use (1) Simple Attack or (2) Special Attack to harm your opponent\n";
        std::cin >> input;

        switch (input) {
        case 1:
            player1->simpleAttack(*player2);
            break;
        case 2:
            player1->specialAttack(*player2);
            break;
        default:
            std::cout << "Invalid input, try again...\n";
            break;
        }

        if (player2->getLifePoints() <= 0)
        {
            std::cout << "Player 1: " << player1->getName() << " wins!\n";
            player1->incrementWins();
            player2->incrementLosses();
            player1->resetLifePoints();
            player2->resetLifePoints();
            isGameOver = true;
            break;
        }

        std::cout << " Player 2: Use (1) Simple Attack or (2) Special Attack to harm your opponent\n";
        std::cin >> input;

        switch (input) {
        case 1:
            player2->simpleAttack(*player1);
            break;
        case 2:
            player2->specialAttack(*player1);
            break;
        default:
            std::cout << "Invalid input, try again...\n";
            break;
        }

        if (player1->getLifePoints() <= 0) {
            std::cout << "Player 2: " << player2->getName() << " wins!\n";
            player2->incrementWins();
            player1->incrementLosses();
            player1->resetLifePoints();
            player2->resetLifePoints();
            isGameOver = true;
            break;
        }
    }
}

void Game::printPlayerStats() {
    std::cout << player1->getName() << "  vs  " << player2->getName() << "\n"
              << "Lifepoints: " << player1->getLifePoints() << "  Simple Attack: " << player1->getSimpleAttackName() << "  Lifepoints: " << player2->getLifePoints() << "  Simple Attack: " << player2->getSimpleAttackName() << "\n"
              << "Wins/Losses: " << player1->getWins() << "/" << player1->getLosses() << "  Special Attack: " << player1->getSpecialAttackName() << "  Wins/Losses: " << player2->getWins() << "/" << player2->getLosses() << "  Special Attack: " << player2->getSpecialAttackName() << "\n\n";
}

Game::~Game() {}
