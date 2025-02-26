// Anhelina Belavezha
#include <iostream>
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"
/////////////////////////////////////////////////////////////////////getters i setters
TREE_CLASS *BRANCH_CLASS::getBranchTree()
{
    return branchTree;
}

void BRANCH_CLASS::setBranchTree(TREE_CLASS *tree)
{
    branchTree = tree;
}

unsigned int BRANCH_CLASS::getTreeHeight()
{
    return treeHeight;
}

void BRANCH_CLASS::setTreeHeight(unsigned int height)
{
    treeHeight = height;
}

unsigned int BRANCH_CLASS::getBranchLength()
{
    return branchLength;
}

void BRANCH_CLASS::setBranchLength(unsigned int length)
{
    branchLength = length;
}

FRUIT_CLASS *BRANCH_CLASS::getFirstFruit()
{
    return firstFruit;
}

void BRANCH_CLASS::setFirstFruit(FRUIT_CLASS *first)
{
    firstFruit = first;
}

FRUIT_CLASS *BRANCH_CLASS::getLastFruit()
{
    return lastFruit;
}

void BRANCH_CLASS::setLastFruit(FRUIT_CLASS *last)
{
    lastFruit = last;
}

unsigned int BRANCH_CLASS::getFruitsNumber()
{
    return fruitsNumber;
}

void BRANCH_CLASS::setFruitsNumber(unsigned int number)
{
    fruitsNumber = number;
}

unsigned int BRANCH_CLASS::getFruitsWeight()
{
    return fruitsWeight;
}

void BRANCH_CLASS::setFruitsWeight(unsigned int weight)
{
    fruitsWeight = weight;
}

BRANCH_CLASS *BRANCH_CLASS::getNextBranch()
{
    return next;
}

void BRANCH_CLASS::setNextBranch(BRANCH_CLASS *nextBranch)
{
    next = nextBranch;
}

BRANCH_CLASS *BRANCH_CLASS::getPreviousBranch()
{
    return previous;
}

void BRANCH_CLASS::setPreviousBranch(BRANCH_CLASS *previousBranch)
{
    previous = previousBranch;
}

unsigned int BRANCH_CLASS::getFruitsTotal()
{
    return fruitsNumber;
}

unsigned int BRANCH_CLASS::getWeightsTotal()
{
    return fruitsWeight;
}

unsigned int BRANCH_CLASS::getHeight()
{
    return treeHeight;
}

unsigned int BRANCH_CLASS::getLength()
{
    return branchLength;
}
/////////////////////////////////////////////////////////////////////konstruktory i destruktor
BRANCH_CLASS::BRANCH_CLASS()
{
    branchTree = NULL;
    treeHeight = 0;
    branchLength = 0;
    firstFruit = NULL;
    lastFruit = NULL;
    fruitsNumber = 0;
    fruitsWeight = 0;
    next = NULL;
    previous = NULL;
}

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS *branchTree, unsigned int treeHeight)
{
    this->branchTree = branchTree;
    this->treeHeight = treeHeight;

    branchLength = 0;
    firstFruit = NULL;
    lastFruit = NULL;
    fruitsNumber = 0;
    fruitsWeight = 0;

    if (branchTree != NULL)
    {
        branchTree->setBranchesNumber(branchTree->getBranchesNumber() + 1);
        if (branchTree->getGardenPointer() != NULL)
        {
            branchTree->getGardenPointer()->setBranchesNumber(branchTree->getGardenPointer()->getBranchesNumber() + 1);
        }
    }

    next = NULL;
    previous = NULL;
}

BRANCH_CLASS::~BRANCH_CLASS()
{
    if (branchTree != NULL)
    {
        branchTree->setBranchesNumber(branchTree->getBranchesNumber() - 1);
        if (branchTree->getTreeGarden() != NULL)
        {
            branchTree->getTreeGarden()->setBranchesNumber(branchTree->getTreeGarden()->getBranchesNumber() - 1);
        }
    }

    FRUIT_CLASS *first = firstFruit;
    FRUIT_CLASS *second;
    while (first != NULL)
    {
        second = first->getNextFruit();
        delete first;
        first = second;
    }
}
///////////////////////////////////////////////////////////////////////konstruktor kopiujacy
BRANCH_CLASS::BRANCH_CLASS(BRANCH_CLASS &copy, unsigned int treeHeight, TREE_CLASS *branchTree)
{
    this->treeHeight = treeHeight;
    this->branchTree = branchTree;
    this->branchLength = copy.branchLength;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->next = NULL;
    this->previous = NULL;

    if (copy.firstFruit == NULL)
    {
        firstFruit = NULL;
        lastFruit = NULL;
        if (branchTree != NULL)
        {
            branchTree->setBranchesNumber(branchTree->getBranchesNumber() + 1);
            if (branchTree->getGardenPointer() != NULL)
            {
                branchTree->getGardenPointer()->setBranchesNumber(branchTree->getGardenPointer()->getBranchesNumber() + 1);
            }
        }
        return;
    }

    firstFruit = new FRUIT_CLASS(*(copy.firstFruit), this);
    FRUIT_CLASS *actualcopy = copy.firstFruit;
    FRUIT_CLASS *actual = firstFruit;
    FRUIT_CLASS *prev = NULL;

    while (actualcopy->getNextFruit() != NULL)
    {
        actual->setNextFruit(new FRUIT_CLASS(*(actualcopy->getNextFruit()), this));
        actual->setPreviousFruit(prev);

        prev = actual;
        actual = actual->getNextFruit();
        actualcopy = actualcopy->getNextFruit();
    }

    actual->setPreviousFruit(prev);
    actual->setNextFruit(NULL);
    lastFruit = actual;

    if (branchTree != NULL)
    {
        branchTree->setBranchesNumber(branchTree->getBranchesNumber() + 1);
        if (branchTree->getGardenPointer() != NULL)
        {
            branchTree->getGardenPointer()->setBranchesNumber(branchTree->getGardenPointer()->getBranchesNumber() + 1);
        }
    }
}
////////////////////////////////////////////////////////////////////////metody
void BRANCH_CLASS::growthBranch()
{
    branchLength += 1;

    FRUIT_CLASS *actual = firstFruit;

    while (actual != NULL)
    {
        actual->growthFruit();
        actual = actual->getNextFruit();
    }

    if (branchLength > 0 && branchLength % 2 == 0)
    {
        FRUIT_CLASS *fruitPointer = new FRUIT_CLASS(this, 0, branchLength);

        if (firstFruit == NULL)
        {
            firstFruit = fruitPointer;
            firstFruit->setPreviousFruit(NULL);
            firstFruit->setNextFruit(NULL);
            lastFruit = firstFruit;
        }
        else
        {
            lastFruit->setNextFruit(fruitPointer);
            FRUIT_CLASS *tempo = lastFruit;
            lastFruit = fruitPointer;
            lastFruit->setPreviousFruit(tempo);
            lastFruit->setNextFruit(NULL);
        }
    }
}

void BRANCH_CLASS::fadeBranch()
{
    if (branchLength == 0)
        return;

    FRUIT_CLASS *actual = firstFruit;
    while (actual != NULL)
    {
        actual->fadeFruit();
        actual = actual->getNextFruit();
    }

    if (lastFruit != NULL && lastFruit->getLength() == branchLength)
    {
        FRUIT_CLASS *newlast = lastFruit->getPreviousFruit();
        if (newlast == NULL)
        {
            firstFruit = NULL;
            delete lastFruit;
            lastFruit = NULL;
        }
        else
        {
            newlast->setNextFruit(NULL);
            delete lastFruit;
            lastFruit = newlast;
        }
    }
    branchLength -= 1;
}

void BRANCH_CLASS::harvestBranch(unsigned int fruitWeight)
{
    FRUIT_CLASS *actual = firstFruit;
    while (actual != NULL)
    {
        if (actual->getWeight() >= fruitWeight)
            actual->pluckFruit();
        actual = actual->getNextFruit();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int branchLength)
{
    if (this->branchLength <= branchLength)
        return;
    this->branchLength = branchLength;

    FRUIT_CLASS *actual = lastFruit;
    if (actual == NULL)
        return;

    FRUIT_CLASS *prevactual;
    while (actual != NULL && actual->getLength() > branchLength)
    {
        prevactual = actual;
        actual = actual->getPreviousFruit();
        delete prevactual;
    }

    lastFruit = actual;
    if (actual != NULL)
        lastFruit->setNextFruit(NULL);
    if (actual == NULL)
        firstFruit = NULL;
}

FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int length)
{
    FRUIT_CLASS *actual = firstFruit;

    while (actual != NULL)
    {
        if (actual->getLength() == length)
            return actual;
        actual = actual->getNextFruit();
    }
    return NULL;
}

TREE_CLASS *BRANCH_CLASS::getTreePointer()
{
    return branchTree;
}