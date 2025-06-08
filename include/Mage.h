#ifndef MAGE_H
#define MAGE_H
#include "Character.h"
#include <string>


class Mage : public Character
{
    public:
        Mage();
        virtual ~Mage();

        void simpleAttack(Character& opponent);
        void specialAttack(Character& opponent);
        void resetLifePoints() override;

    protected:

    private:
};

#endif // MAGE_H
