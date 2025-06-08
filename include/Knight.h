#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"
#include <string>


class Knight : public Character
{
    public:
        Knight();
        virtual ~Knight();

        void simpleAttack(Character& opponent);
        void specialAttack(Character& opponent);
        void resetLifePoints() override;

    protected:

    private:

};

#endif // KNIGHT_H
