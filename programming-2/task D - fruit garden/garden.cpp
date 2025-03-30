// Anhelina Belavezha
#include <iostream>
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
/////////////////////////////////////////////////////////////////////getters i setters
unsigned int GARDEN_CLASS::getTreesNumber()
{
    return treesNumber;
}

void GARDEN_CLASS::setTreesNumber(unsigned int number)
{
    treesNumber = number;
}

unsigned int GARDEN_CLASS::getBranchesNumber()
{
    return branchesNumber;
}

void GARDEN_CLASS::setBranchesNumber(unsigned int number)
{
    branchesNumber = number;
}

unsigned int GARDEN_CLASS::getFruitsNumber()
{
    return fruitsNumber;
}

void GARDEN_CLASS::setFruitsNumber(unsigned int number)
{
    fruitsNumber = number;
}

unsigned int GARDEN_CLASS::getFruitsWeight()
{
    return fruitsWeight;
}

void GARDEN_CLASS::setFruitsWeight(unsigned int weight)
{
    fruitsWeight = weight;
}

TREE_CLASS *GARDEN_CLASS::getFirstTree()
{
    return firstTree;
}

void GARDEN_CLASS::setFirstTree(TREE_CLASS *first)
{
    firstTree = first;
}

TREE_CLASS *GARDEN_CLASS::getLastTree()
{
    return lastTree;
}

void GARDEN_CLASS::setLastTree(TREE_CLASS *last)
{
    lastTree = last;
}

unsigned int GARDEN_CLASS::getEmpty()
{
    return empty;
}

void GARDEN_CLASS::setEmpty(unsigned int number)
{
    empty = number;
}
/////////////////////////////////////////////////////////////////konstruktory i destruktor
GARDEN_CLASS::GARDEN_CLASS()
{
    treesNumber = 0;
    branchesNumber = 0;
    fruitsNumber = 0;
    fruitsWeight = 0;
    firstTree = NULL;
    lastTree = NULL;
    empty = 0;
}

GARDEN_CLASS::~GARDEN_CLASS()
{
    TREE_CLASS *actual = firstTree;

    while (actual != NULL)
    {
        TREE_CLASS *tempo = actual->getNextTree();
        delete actual;
        actual = tempo;
    }
}
////////////////////////////////////////////////////////////////metody
unsigned int GARDEN_CLASS::getTreesTotal()
{
    return treesNumber;
}

unsigned int GARDEN_CLASS::getBranchesTotal()
{
    return branchesNumber;
}

unsigned int GARDEN_CLASS::getFruitsTotal()
{
    return fruitsNumber;
}

unsigned int GARDEN_CLASS::getWeightsTotal()
{
    return fruitsWeight;
}

void GARDEN_CLASS::plantTree()
{
    if (treesNumber == 0)
    {
        firstTree = new TREE_CLASS(0, this);
        lastTree = firstTree;
    }
    else if (empty == 0)
    {
        lastTree->setNextTree(new TREE_CLASS(lastTree->getNumber() + 1, this));
        lastTree->getNextTree()->setPreviousTree(lastTree);
        lastTree = lastTree->getNextTree();
        lastTree->setNextTree(NULL);
    }
    else
    {
        empty -= 1;
        unsigned int prev = firstTree->getNumber();
        TREE_CLASS *actual = firstTree;

        if (firstTree->getNumber() != 0)
        {
            firstTree->setPreviousTree(new TREE_CLASS(firstTree->getNumber() - 1, this));
            firstTree->getPreviousTree()->setNextTree(firstTree);
            firstTree = firstTree->getPreviousTree();
            firstTree->setPreviousTree(NULL);
            return;
        }
        while (actual->getNextTree() != NULL)
        {
            if (actual->getNextTree()->getNumber() != (prev + 1))
                break;
            actual = actual->getNextTree();
            prev = actual->getNumber();
        }
        TREE_CLASS *actualafter = actual->getNextTree();
        actual->setNextTree(new TREE_CLASS(actual->getNumber() + 1, this));
        actual->getNextTree()->setPreviousTree(actual);
        actual->getNextTree()->setNextTree(actualafter);
        actualafter->setPreviousTree(actual->getNextTree());
    }
}

void GARDEN_CLASS::extractTree(unsigned int treeNumber)
{
    bool isTree = false;

    TREE_CLASS *actual = lastTree;
    while (actual != NULL)
    {
        if (actual->getNumber() == treeNumber)
        {
            isTree = true;
            break;
        }
        actual = actual->getPreviousTree();
    }
    if (isTree)
    {
        if (actual == firstTree && firstTree == lastTree)
        {
            delete actual;
            firstTree = NULL;
            lastTree = NULL;
        }
        else if (actual == firstTree)
        {
            TREE_CLASS *copy = firstTree->getNextTree();
            firstTree->getNextTree()->setPreviousTree(NULL);
            empty += 1;
            delete firstTree;
            firstTree = copy;
        }
        else if (actual == lastTree)
        {
            TREE_CLASS *beforelast = lastTree->getPreviousTree();
            lastTree->getPreviousTree()->setNextTree(NULL);
            delete lastTree;
            lastTree = beforelast;
        }
        else
        {
            actual->getPreviousTree()->setNextTree(actual->getNextTree());
            actual->getNextTree()->setPreviousTree(actual->getPreviousTree());
            empty += 1;
            delete actual;
        }
    }
}

void GARDEN_CLASS::growthGarden()
{
    TREE_CLASS *actual = firstTree;
    while (actual != NULL)
    {
        actual->growthTree();
        actual = actual->getNextTree();
    }
}

void GARDEN_CLASS::fadeGarden()
{
    TREE_CLASS *actual = firstTree;
    while (actual != NULL)
    {
        actual->fadeTree();
        actual = actual->getNextTree();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int weight)
{
    TREE_CLASS *actual = firstTree;
    while (actual != NULL)
    {
        actual->harvestTree(weight);
        actual = actual->getNextTree();
    }
}

TREE_CLASS *GARDEN_CLASS::getTreePointer(unsigned int treeNumber)
{
    TREE_CLASS *actual = lastTree;
    while (actual != NULL)
    {
        if (actual->getNumber() == treeNumber)
            return actual;
        actual = actual->getPreviousTree();
    }
    return NULL;
}

void GARDEN_CLASS::cloneTree(unsigned int treeNumber)
{
    unsigned int newTreeNumber = 0;
    TREE_CLASS *clone = getTreePointer(treeNumber);
    if (clone == NULL)
        return;

    if (empty == 0)
    {
        lastTree->setNextTree(new TREE_CLASS(*clone, lastTree->getNumber() + 1, this));
        lastTree->getNextTree()->setPreviousTree(lastTree);
        lastTree = lastTree->getNextTree();
    }
    else
    {
        TREE_CLASS *actual = firstTree;
        while (actual != NULL)
        {
            if (actual->getNumber() != newTreeNumber)
                break;
            actual = actual->getNextTree();
        }

        TREE_CLASS *newTree = new TREE_CLASS(*clone, newTreeNumber, this);

        if (actual != NULL)
        {
            newTree->setNextTree(actual);
            actual->setPreviousTree(actual->getPreviousTree());
            if (actual->getPreviousTree() != NULL)
                actual->getPreviousTree()->setNextTree(newTree);
            actual->setPreviousTree(newTree);
            empty -= 1;
        }
        else
        {
            lastTree->setNextTree(newTree);
            newTree->setPreviousTree(lastTree);
            lastTree = newTree;
            empty = 0;
        }
    }
}
