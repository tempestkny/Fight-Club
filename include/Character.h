#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>


class Character
{
    public:
        Character(int lifePoints, std::string name, std::string simpleAttackName, std::string specialAttackName);
        virtual ~Character();

        // getter
        std::string getName() const;
        std::string getSimpleAttackName();
        std::string getSpecialAttackName();
        int getLifePoints();
        int getWins();
        int getLosses();

        // setter
        virtual void resetLifePoints() = 0;

        // functions
        virtual void simpleAttack(Character& opponent);
        virtual void specialAttack(Character& opponent);

        void takeDamage(int damage);
        void incrementWins();
        void incrementLosses();

        static std::vector<Character*> allCharacters;
        static void printAllCharacterStats();
        static Character* findCharacterByName(const std::string& name);


    protected:
        // stats
        int lifePoints;
        std::string name;
        std::string simpleAttackName;
        std::string specialAttackName;
        int wins;
        int losses;
    private:

};

#endif // CHARACTER_H
