// Anhelina Belavezha
#include <iostream>
#include <string>
using namespace std;

class PLAYER_CLASS
{
protected:
    PLAYER_CLASS *next;
    unsigned int maxHP;
    unsigned int currentHP;
    unsigned int attack;
    unsigned int agility;

    virtual void die()
    {
        currentHP = 0;
    }

public:
    PLAYER_CLASS()
    {
        next = 0;
    }

    virtual unsigned int getRemainingHealth()
    {
        return (currentHP * 100 / maxHP);
    }

    virtual unsigned int getDamage() = 0;

    virtual void takeDamage(unsigned int damage) = 0;

    virtual void applyWinnerReward()
    {
        attack += 2;
        agility += 2;
    }

    virtual void cure()
    {
        currentHP = maxHP;
    }

    virtual void printParams() = 0;
    ////////////////////////////////////////////////////////////
    virtual string getID()
    {
        return "";
    }

    virtual unsigned int getDefense()
    {
        return 0;
    }

    virtual unsigned int getAgility()
    {
        return agility;
    }

    friend class CAESAR_CLASS;
    friend class ARENA_CLASS;
    friend class SQUAD_CLASS;
};

class CAESAR_CLASS
{
public:
    int judge;

    void judgeDeathOrLife(PLAYER_CLASS *player)
    {
        judge++;
        if (judge % 3 == 0 && judge != 0)
        {
            judge = 0;
            player->die();
        }
    }
};

class ARENA_CLASS
{
private:
    CAESAR_CLASS cesar;

public:
    ARENA_CLASS(CAESAR_CLASS *cesarvalue)
    {
        cesar = *cesarvalue;
        cesar.judge = 0;
    }

    void fight(PLAYER_CLASS *player1, PLAYER_CLASS *player2)
    {
        PLAYER_CLASS *firstPlayer;
        PLAYER_CLASS *secondPlayer;
        int numberAttack = 0;

        if (player1->getRemainingHealth() != 0 && player2->getRemainingHealth() != 0)
        {
            if (player1->getAgility() < player2->getAgility())
            {
                firstPlayer = player2;
                secondPlayer = player1;
            }
            else
            {
                firstPlayer = player1;
                secondPlayer = player2;
            }

            firstPlayer->printParams();
            secondPlayer->printParams();

            while (numberAttack < 40 && firstPlayer->getRemainingHealth() >= 10 && secondPlayer->getRemainingHealth() >= 10)
            {
                secondPlayer->takeDamage(firstPlayer->getDamage());
                secondPlayer->printParams();
                numberAttack++;

                if (secondPlayer->getRemainingHealth() >= 10)
                {
                    firstPlayer->takeDamage(secondPlayer->getDamage());
                    firstPlayer->printParams();
                    numberAttack++;
                }
            }

            if (firstPlayer->getRemainingHealth() == 0)
            {
                firstPlayer->die();
            }
            if (secondPlayer->getRemainingHealth() == 0)
            {
                secondPlayer->die();
            }

            if (numberAttack % 2 == 0)
            {
                if (firstPlayer->getRemainingHealth() != 0)
                {
                    cesar.judgeDeathOrLife(firstPlayer);
                    firstPlayer->printParams();
                }
                if (secondPlayer->getRemainingHealth() != 0)
                {
                    cesar.judgeDeathOrLife(secondPlayer);
                    secondPlayer->printParams();
                }
            }
            else
            {
                if (firstPlayer->getRemainingHealth() != 0)
                {
                    cesar.judge++;
                    firstPlayer->printParams();
                }
                if (secondPlayer->getRemainingHealth() != 0)
                {
                    cesar.judge++;
                    secondPlayer->printParams();
                }
            }

            if (firstPlayer->getRemainingHealth() != 0)
            {
                firstPlayer->applyWinnerReward();
                firstPlayer->cure();
            }
            if (secondPlayer->getRemainingHealth() != 0)
            {
                secondPlayer->applyWinnerReward();
                secondPlayer->cure();
            }

            firstPlayer->printParams();
            secondPlayer->printParams();
        }
    }
};

class HUMAN_CLASS : virtual public PLAYER_CLASS
{
protected:
    string id;
    unsigned int defense;

public:
    HUMAN_CLASS(string idvalue)
    {
        id = idvalue;
        maxHP = 200;
        currentHP = 200;
        attack = 30;
        agility = 10;
        defense = 10;
    }

    string getID()
    {
        return id;
    }

    unsigned int getDefense()
    {
        return defense;
    }

    unsigned int getAgility()
    {
        return agility;
    }

    unsigned int getDamage()
    {
        return attack;
    }

    unsigned int getRemainingHealth()
    {
        return (currentHP * 100 / maxHP);
    }

    void takeDamage(unsigned int damage)
    {
        if (damage > defense + agility)
        {
            if ((int)(currentHP - (damage - (defense + agility))) <= 0)
                this->die();
            else
                currentHP -= (damage - (defense + agility));
        }
    }

    void printParams()
    {
        if (currentHP != 0)
        {
            cout << id << ":" << maxHP << ":" << currentHP << ":" << this->getRemainingHealth() << "%:" << this->getDamage() << ":" << this->getAgility() << ":" << defense << endl;
        }
        else
        {
            cout << id << ":" << "R.I.P." << endl;
        }
    };
};

class BEAST_CLASS : virtual public PLAYER_CLASS
{
protected:
    string id;

public:
    BEAST_CLASS(string idvalue)
    {
        id = idvalue;
        maxHP = 150;
        currentHP = 150;
        attack = 40;
        agility = 20;
    }

    string getID()
    {
        return id;
    }

    unsigned int getDefense()
    {
        return 0;
    }

    unsigned int getAgility()
    {
        return agility;
    }

    unsigned int getRemainingHealth()
    {
        return (currentHP * 100 / maxHP);
    }

    unsigned int getDamage()
    {
        if ((currentHP * 100 / maxHP) < 25)
            return attack * 2;
        return attack;
    }

    void takeDamage(unsigned int damage)
    {
        if (damage > 0.5 * agility)
        {
            if ((int)(currentHP - (damage - (0.5 * agility))) <= 0)
                this->die();
            else
                currentHP -= (damage - (0.5 * agility));
        }
    }

    void printParams()
    {
        if (currentHP != 0)
        {
            cout << id << ":" << maxHP << ":" << currentHP << ":" << this->getRemainingHealth() << "%:" << this->getDamage() << ":" << this->getAgility() << endl;
        }
        else
        {
            cout << id << ":" << "R.I.P." << endl;
        }
    };
};

class BERSERKER_CLASS : virtual public HUMAN_CLASS, virtual public BEAST_CLASS
{
public:
    BERSERKER_CLASS(string idHuman, string idBeast) : HUMAN_CLASS(idHuman), BEAST_CLASS(idBeast)
    {
        maxHP = 200;
        currentHP = 200;
        attack = 35;
        agility = 5;
        defense = 15;
    }

    string getID()
    {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::id;
        else
            return BEAST_CLASS::id;
    }

    unsigned int getDefense()
    {
        return defense;
    }

    unsigned int getRemainingHealth()
    {
        return (currentHP * 100 / maxHP);
    }

    unsigned int getAgility()
    {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::getAgility();
        else
            return BEAST_CLASS::getAgility();
    }

    unsigned int getDamage()
    {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::getDamage();
        else
            return BEAST_CLASS::getDamage();
    }

    void takeDamage(unsigned int damage)
    {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            HUMAN_CLASS::takeDamage(damage);
        else
            BEAST_CLASS::takeDamage(damage);
    }

    void printParams()
    {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            HUMAN_CLASS::printParams();
        else
            BEAST_CLASS::printParams();
    }
};

class SQUAD_CLASS : public PLAYER_CLASS
{
protected:
    string id;
    PLAYER_CLASS *first;

public:
    SQUAD_CLASS(string idvalue)
    {
        id = idvalue;
        maxHP = 1;
        currentHP = 0;
        first = 0;
    }

    void addPlayer(PLAYER_CLASS *addplayer)
    {
        if (addplayer->getRemainingHealth() != 0)
        {
            if (first == NULL)
            {
                first = addplayer;
            }
            else
            {
                PLAYER_CLASS *pointer = first;
                while (pointer->next != NULL)
                {
                    if (pointer == addplayer)
                        return;
                    pointer = pointer->next;
                }
                pointer->next = addplayer;
                pointer->next->next = NULL;
            }

            PLAYER_CLASS *pointer = first;
            currentHP = 0;
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() > getRemainingHealth())
                {
                    currentHP = pointer->currentHP;
                    maxHP = pointer->maxHP;
                }
                pointer = pointer->next;
            }
            Sort();
        }
    }

    string getID()
    {
        return id;
    }

    unsigned int getRemainingHealth()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            unsigned int counterRemainingHealth = 0;

            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() > counterRemainingHealth)
                    counterRemainingHealth = pointer->getRemainingHealth();
                pointer = pointer->next;
            }
            return counterRemainingHealth;
        }
        return 0;
    }

    unsigned int getDefense()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            int counterDefense = 0;
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                    counterDefense += pointer->getDefense();
                pointer = pointer->next;
            }
            return counterDefense;
        }
        return 0;
    }

    unsigned int getAgility()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            int counterAgility = -1;
            if (pointer->getRemainingHealth() != 0)
                counterAgility = pointer->getAgility();
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                {
                    if (counterAgility > pointer->getAgility())
                        counterAgility = pointer->getAgility();
                }
                pointer = pointer->next;
            }
            return counterAgility;
        }
        return 0;
    }

    void applyWinnerReward()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                    pointer->applyWinnerReward();
                pointer = pointer->next;
            }
        }
    }

    unsigned int getDamage()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            int damageCounter = 0;
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                    damageCounter += pointer->getDamage();
                pointer = pointer->next;
            }
            return damageCounter;
        }
        return 0;
    }

    void takeDamage(unsigned int damage)
    {
        PLAYER_CLASS *pointer = first;
        PLAYER_CLASS *prevpointer = NULL;
        int playerCount = this->countPlayers();

        if (countPlayers() != 0)
        {
            while (pointer != NULL)
            {
                pointer->takeDamage((damage / playerCount));
                if (pointer->getRemainingHealth() == 0)
                {
                    if (prevpointer != NULL)
                    {
                        prevpointer->next = pointer->next;
                    }
                    else
                    {
                        first = first->next;
                    }
                }
                else
                {
                    prevpointer = pointer;
                }
                pointer = pointer->next;
            }
        }
    }

    int countPlayers()
    {
        PLAYER_CLASS *pointer = first;
        int playerCounter = 0;
        while (pointer != NULL)
        {
            playerCounter++;
            pointer = pointer->next;
        }
        return playerCounter;
    }

    bool IsGreater(PLAYER_CLASS *player1, PLAYER_CLASS *player2)
    {
        return (player1->getID() > player2->getID()) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP > player2->maxHP) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP == player2->maxHP &&
                player1->currentHP > player2->currentHP) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP == player2->maxHP &&
                player1->currentHP == player2->currentHP &&
                player1->getRemainingHealth() > player2->getRemainingHealth()) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP == player2->maxHP &&
                player1->currentHP == player2->currentHP &&
                player1->getRemainingHealth() == player2->getRemainingHealth() &&
                player1->getDamage() > player2->getDamage()) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP == player2->maxHP &&
                player1->currentHP == player2->currentHP &&
                player1->getRemainingHealth() == player2->getRemainingHealth() &&
                player1->getDamage() == player2->getDamage() &&
                player1->getAgility() > player2->getAgility()) ||
               (player1->getID() == player2->getID() &&
                player1->maxHP == player2->maxHP &&
                player1->currentHP == player2->currentHP &&
                player1->getRemainingHealth() == player2->getRemainingHealth() &&
                player1->getDamage() == player2->getDamage() &&
                player1->getAgility() == player2->getAgility() &&
                player1->getDefense() > player2->getDefense());
    }

    void Sort()
    {
        int count = countPlayers();
        for (int i = count; i > 1; i--)
        {
            PLAYER_CLASS *temp, *player1;
            player1 = first;

            for (int j = 0; j < count - 1; j++)
            {
                if (IsGreater(player1, player1->next))
                {
                    PLAYER_CLASS *player2 = player1->next;
                    player1->next = player2->next;
                    player2->next = player1;

                    if (player1 == first)
                    {
                        first = player2;
                        player1 = player2;
                    }
                    else
                    {
                        player1 = player2;
                        temp->next = player2;
                    }
                }
                temp = player1;
                player1 = player1->next;
            }
        }
    }

    void printParams()
    {
        if (countPlayers() != 0)
        {
            cout << id << ":" << countPlayers() << ":" << getRemainingHealth() << "%" << ":" << getDamage() << ":" << getAgility() << endl;
            Sort();

            PLAYER_CLASS *pointer = first;
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                    pointer->printParams();
                pointer = pointer->next;
            }
        }
        else
        {
            cout << id << ":" << "nemo" << endl;
        }
    }

    void die()
    {
        PLAYER_CLASS *pointer = first;
        if (pointer != NULL)
        {
            while (pointer != NULL)
            {
                pointer->currentHP = 0;
                pointer = pointer->next;
            }
            currentHP = 0;
        }
    }

    void cure()
    {
        PLAYER_CLASS *pointer = first;
        if (countPlayers() != 0)
        {
            while (pointer != NULL)
            {
                if (pointer->getRemainingHealth() != 0)
                    pointer->currentHP = pointer->maxHP;
                if (pointer->getRemainingHealth() > getRemainingHealth())
                {
                    currentHP = pointer->currentHP;
                    maxHP = pointer->maxHP;
                }
                pointer = pointer->next;
            }
        }
    }
};