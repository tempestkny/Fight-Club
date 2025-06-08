#ifndef GAME_H
#define GAME_H
#include "Character.h"


class Game
{
    public:
        Game();
        virtual ~Game();

        // functions
        void run();
        void printPlayerStats();

    protected:

    private:
        Character* player1;
        Character* player2;
        bool isGameOver;
};

#endif // GAME_H
