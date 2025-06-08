#include "Game.h"
#include <iostream>

int main()
{
    char playAgain = 'y';

    do {
        Game game;
        game.run();

        std::cout << "Show stats? (y/n)\n";
        char showStats;
        std::cin >> showStats;
        if (showStats == 'y') {
            Character::printAllCharacterStats();
        }

        std::cout << "Play again? (y/n)\n";
        std::cin >> playAgain;
    } while (playAgain == 'y');

    for (Character* c : Character::allCharacters) {
        delete c;
    }
    Character::allCharacters.clear();

    return 0;
}
