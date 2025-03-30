// Anhelina Belavezha
#include <iostream>
class TREE_CLASS;

class GARDEN_CLASS
{
private:
    unsigned int treesNumber;
    unsigned int branchesNumber;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    TREE_CLASS *firstTree;
    TREE_CLASS *lastTree;
    unsigned int empty;

public:
    unsigned int getTreesNumber();
    void setTreesNumber(unsigned int number);

    unsigned int getBranchesNumber();
    void setBranchesNumber(unsigned int number);

    unsigned int getFruitsNumber();
    void setFruitsNumber(unsigned int number);

    unsigned int getFruitsWeight();
    void setFruitsWeight(unsigned int weight);

    TREE_CLASS *getFirstTree();
    void setFirstTree(TREE_CLASS *first);

    TREE_CLASS *getLastTree();
    void setLastTree(TREE_CLASS *last);

    unsigned int getEmpty();
    void setEmpty(unsigned int number);

    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void plantTree();
    void extractTree(unsigned int treeNumber);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int weight);
    TREE_CLASS *getTreePointer(unsigned int treeNumber);
    void cloneTree(unsigned int treeNumber);

    GARDEN_CLASS();
    ~GARDEN_CLASS();
};