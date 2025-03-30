// Anhelina Belavezha
#include <iostream>
class GARDEN_CLASS;
class BRANCH_CLASS;

class TREE_CLASS
{
private:
    GARDEN_CLASS *treeGarden;
    unsigned int treeNumber;
    unsigned int treeHeight;
    unsigned int branchesNumber;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    BRANCH_CLASS *firstBranch;
    BRANCH_CLASS *lastBranch;
    TREE_CLASS *next;
    TREE_CLASS *previous;

public:
    GARDEN_CLASS *getTreeGarden();
    void setTreeGarden(GARDEN_CLASS *garden);

    unsigned int getTreeNumber();
    void setTreeNumber(unsigned int number);

    unsigned int getTreeHeight();
    void setTreeHeight(unsigned int height);

    unsigned int getBranchesNumber();
    void setBranchesNumber(unsigned int number);

    unsigned int getFruitsNumber();
    void setFruitsNumber(unsigned int number);

    unsigned int getFruitsWeight();
    void setFruitsWeight(unsigned int weight);

    BRANCH_CLASS *getFirstBranch();
    void setFirstBranch(BRANCH_CLASS *first);

    BRANCH_CLASS *getLastBranch();
    void setLastBranch(BRANCH_CLASS *last);

    TREE_CLASS *getNextTree();
    void setNextTree(TREE_CLASS *nextTree);

    TREE_CLASS *getPreviousTree();
    void setPreviousTree(TREE_CLASS *previousTree);

    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int fruitWeight);
    void cutTree(unsigned int treeHeight);
    void cloneBranch(BRANCH_CLASS *branch);
    GARDEN_CLASS *getGardenPointer();
    BRANCH_CLASS *getBranchPointer(unsigned int height);

    TREE_CLASS();
    ~TREE_CLASS();
    TREE_CLASS(unsigned int treeNumber, GARDEN_CLASS *treeGarden);
    TREE_CLASS(TREE_CLASS &copy, unsigned int treeNumber = 0, GARDEN_CLASS *treeGarden = NULL);
};
