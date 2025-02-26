// Anhelina Belavezha
#include <iostream>
class BRANCH_CLASS;

class FRUIT_CLASS
{
private:
    unsigned int fruitBranchLength;
    unsigned int fruitWeight;
    BRANCH_CLASS *fruitBranch;
    FRUIT_CLASS *next;
    FRUIT_CLASS *previous;

public:
    unsigned int getLength();
    void setFruitBranchLength(unsigned int);

    unsigned int getWeight();
    void setFruitWeight(unsigned int);

    BRANCH_CLASS *getFruitBranch();
    void setFruitBranch(BRANCH_CLASS *branch);

    FRUIT_CLASS *getNextFruit();
    void setNextFruit(FRUIT_CLASS *nextFruit);

    FRUIT_CLASS *getPreviousFruit();
    void setPreviousFruit(FRUIT_CLASS *previousFruit);

    FRUIT_CLASS();
    ~FRUIT_CLASS();
    FRUIT_CLASS(BRANCH_CLASS *fruitBranch, unsigned int fruitWeight, unsigned int fruitBranchLength);
    FRUIT_CLASS(FRUIT_CLASS &copy, BRANCH_CLASS *fruitBranch);

    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS *getBranchPointer();
};