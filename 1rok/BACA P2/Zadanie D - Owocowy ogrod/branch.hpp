// Anhelina Belavezha
#include <iostream>
class FRUIT_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;

class BRANCH_CLASS
{
private:
    TREE_CLASS *branchTree;
    unsigned int treeHeight;
    unsigned int branchLength;
    FRUIT_CLASS *firstFruit;
    FRUIT_CLASS *lastFruit;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    BRANCH_CLASS *next;
    BRANCH_CLASS *previous;

public:
    TREE_CLASS *getBranchTree();
    void setBranchTree(TREE_CLASS *tree);

    unsigned int getTreeHeight();
    void setTreeHeight(unsigned int height);

    unsigned int getBranchLength();
    void setBranchLength(unsigned int length);

    FRUIT_CLASS *getFirstFruit();
    void setFirstFruit(FRUIT_CLASS *first);

    FRUIT_CLASS *getLastFruit();
    void setLastFruit(FRUIT_CLASS *last);

    unsigned int getFruitsNumber();
    void setFruitsNumber(unsigned int number);

    unsigned int getFruitsWeight();
    void setFruitsWeight(unsigned int weight);

    BRANCH_CLASS *getNextBranch();
    void setNextBranch(BRANCH_CLASS *nextBranch);

    BRANCH_CLASS *getPreviousBranch();
    void setPreviousBranch(BRANCH_CLASS *previousBranch);

    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getHeight();
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int fruitWeight);
    void cutBranch(unsigned int branchLength);
    FRUIT_CLASS *getFruitPointer(unsigned int length);
    TREE_CLASS *getTreePointer();

    BRANCH_CLASS();
    ~BRANCH_CLASS();
    BRANCH_CLASS(TREE_CLASS *branchTree, unsigned int treeHeight);
    BRANCH_CLASS(BRANCH_CLASS &copy, unsigned int treeHeight = 0, TREE_CLASS *branchTree = NULL);
};