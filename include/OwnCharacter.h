#ifndef OWNCHARACTER_H
#define OWNCHARACTER_H
#include "Character.h"
#include <string>


class OwnCharacter : public Character
{
    public:
        OwnCharacter(std::string chosenName, std::string chosenBasic, std::string chosenSpecial);
        virtual ~OwnCharacter();

        void simpleAttack(Character& opponent);
        void specialAttack(Character& opponent);
        void resetLifePoints() override;

    protected:

    private:
};

#endif // OWNCHARACTER_H
