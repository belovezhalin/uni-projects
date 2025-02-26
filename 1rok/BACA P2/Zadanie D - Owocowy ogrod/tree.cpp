// Anhelina Belavezha
#include <iostream>
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
/////////////////////////////////////////////////////////////////////////////getters i setters
GARDEN_CLASS *TREE_CLASS::getTreeGarden()
{
    return treeGarden;
}

void TREE_CLASS::setTreeGarden(GARDEN_CLASS *garden)
{
    treeGarden = garden;
}

unsigned int TREE_CLASS::getTreeNumber()
{
    return treeNumber;
}

void TREE_CLASS::setTreeNumber(unsigned int number)
{
    treeNumber = number;
}

unsigned int TREE_CLASS::getTreeHeight()
{
    return treeHeight;
}

void TREE_CLASS::setTreeHeight(unsigned int height)
{
    treeHeight = height;
}

unsigned int TREE_CLASS::getBranchesNumber()
{
    return branchesNumber;
}

void TREE_CLASS::setBranchesNumber(unsigned int number)
{
    branchesNumber = number;
}

unsigned int TREE_CLASS::getFruitsNumber()
{
    return fruitsNumber;
}

void TREE_CLASS::setFruitsNumber(unsigned int number)
{
    fruitsNumber = number;
}

unsigned int TREE_CLASS::getFruitsWeight()
{
    return fruitsWeight;
}

void TREE_CLASS::setFruitsWeight(unsigned int weight)
{
    fruitsWeight = weight;
}

BRANCH_CLASS *TREE_CLASS::getFirstBranch()
{
    return firstBranch;
}

void TREE_CLASS::setFirstBranch(BRANCH_CLASS *first)
{
    firstBranch = first;
}

BRANCH_CLASS *TREE_CLASS::getLastBranch()
{
    return lastBranch;
}

void TREE_CLASS::setLastBranch(BRANCH_CLASS *last)
{
    lastBranch = last;
}

TREE_CLASS *TREE_CLASS::getNextTree()
{
    return next;
}

void TREE_CLASS::setNextTree(TREE_CLASS *nextTree)
{
    next = nextTree;
}

TREE_CLASS *TREE_CLASS::getPreviousTree()
{
    return previous;
}

void TREE_CLASS::setPreviousTree(TREE_CLASS *previousTree)
{
    previous = previousTree;
}
//////////////////////////////////////////////////////////////////////////////konstruktory i destruktor
TREE_CLASS::TREE_CLASS()
{
    treeGarden = NULL;
    treeNumber = 0;
    treeHeight = 0;
    branchesNumber = 0;
    fruitsNumber = 0;
    fruitsWeight = 0;
    firstBranch = NULL;
    lastBranch = NULL;
    next = NULL;
    previous = NULL;
}

TREE_CLASS::TREE_CLASS(unsigned int treeNumber, GARDEN_CLASS *treeGarden)
{
    this->treeGarden = treeGarden;
    this->treeNumber = treeNumber;
    this->treeHeight = 0;
    this->branchesNumber = 0;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->firstBranch = NULL;
    this->lastBranch = NULL;
    this->next = NULL;
    this->previous = NULL;

    if (treeGarden != NULL)
    {
        treeGarden->setTreesNumber(treeGarden->getTreesNumber() + 1);
    }
}

TREE_CLASS::~TREE_CLASS()
{
    BRANCH_CLASS *actual = firstBranch;

    while (actual != NULL)
    {
        BRANCH_CLASS *tempo = actual->getNextBranch();
        delete actual;
        actual = tempo;
    }

    if (treeGarden != NULL)
    {
        treeGarden->setTreesNumber(treeGarden->getTreesNumber() - 1);
    }
}
//////////////////////////////////////////////////////////////////////////////konstruktor kopiujacy
TREE_CLASS::TREE_CLASS(TREE_CLASS &copy, unsigned int treeNumber, GARDEN_CLASS *treeGarden)
{
    this->treeGarden = treeGarden;
    this->treeNumber = treeNumber;
    this->treeHeight = copy.treeHeight;
    this->branchesNumber = 0;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->firstBranch = NULL;
    this->lastBranch = NULL;
    this->next = NULL;
    this->previous = NULL;

    if (copy.firstBranch == NULL)
    {
        firstBranch = NULL;
        lastBranch = NULL;
        if (treeGarden != NULL)
        {
            treeGarden->setTreesNumber(treeGarden->getTreesNumber() + 1);
        }
        return;
    }

    firstBranch = new BRANCH_CLASS(*(copy.firstBranch), copy.firstBranch->getHeight(), this);

    BRANCH_CLASS *actualcopy = copy.firstBranch;
    BRANCH_CLASS *actual = firstBranch;
    BRANCH_CLASS *prev = NULL;

    while (actualcopy->getNextBranch() != NULL)
    {
        actual->setNextBranch(new BRANCH_CLASS(*(actualcopy->getNextBranch()), actualcopy->getNextBranch()->getHeight(), this));
        actual->setPreviousBranch(prev);
        prev = actual;
        actual = actual->getNextBranch();
        actualcopy = actualcopy->getNextBranch();
    }
    actual->setPreviousBranch(prev);
    actual->setNextBranch(NULL);
    lastBranch = actual;

    if (treeGarden != NULL)
    {
        treeGarden->setTreesNumber(treeGarden->getTreesNumber() + 1);
    }
}
//////////////////////////////////////////////////////////////////////////////metody
unsigned int TREE_CLASS::getBranchesTotal()
{
    return branchesNumber;
}

unsigned int TREE_CLASS::getFruitsTotal()
{
    return fruitsNumber;
}

unsigned int TREE_CLASS::getWeightsTotal()
{
    return fruitsWeight;
}

unsigned int TREE_CLASS::getNumber()
{
    return treeNumber;
}

unsigned int TREE_CLASS::getHeight()
{
    return treeHeight;
}

void TREE_CLASS::growthTree()
{
    treeHeight += 1;

    BRANCH_CLASS *actual = firstBranch;

    while (actual != NULL)
    {
        actual->growthBranch();
        actual = actual->getNextBranch();
    }

    if (treeHeight > 0 && treeHeight % 3 == 0)
    {
        BRANCH_CLASS *branchpointer = new BRANCH_CLASS(this, treeHeight);

        if (firstBranch == NULL)
        {
            firstBranch = branchpointer;
            firstBranch->setPreviousBranch(NULL);
            firstBranch->setNextBranch(NULL);
            lastBranch = firstBranch;
        }

        else
        {
            lastBranch->setNextBranch(branchpointer);
            BRANCH_CLASS *tempo = lastBranch;
            lastBranch = branchpointer;
            lastBranch->setPreviousBranch(tempo);
            lastBranch->setNextBranch(NULL);
        }
    }
}

void TREE_CLASS::fadeTree()
{
    if (treeHeight == 0)
        return;

    BRANCH_CLASS *actual = firstBranch;

    while (actual != NULL)
    {
        actual->fadeBranch();
        actual = actual->getNextBranch();
    }

    if (treeHeight % 3 == 0)
    {
        BRANCH_CLASS *newlast = lastBranch->getPreviousBranch();
        if (newlast == NULL)
        {
            firstBranch = NULL;
            delete lastBranch;
            lastBranch = NULL;
        }

        else
        {
            newlast->setNextBranch(NULL);
            delete lastBranch;
            lastBranch = newlast;
        }
    }
    treeHeight -= 1;
}

void TREE_CLASS::harvestTree(unsigned int fruitWeight)
{
    BRANCH_CLASS *actual = firstBranch;

    while (actual != NULL)
    {
        actual->harvestBranch(fruitWeight);
        actual = actual->getNextBranch();
    }
}

void TREE_CLASS::cutTree(unsigned int treeHeight)
{
    if (this->treeHeight <= treeHeight)
        return;

    this->treeHeight = treeHeight;
    BRANCH_CLASS *actual = lastBranch;

    while (actual != NULL && actual->getHeight() > treeHeight)
    {
        BRANCH_CLASS *tempo = actual->getPreviousBranch();
        delete actual;
        actual = tempo;
    }

    if (actual == NULL)
        firstBranch = NULL;
    lastBranch = actual;
    if (actual != NULL)
        lastBranch->setNextBranch(NULL);
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS *branch)
{
    if (branch == NULL)
        return;

    bool isBranch = false;
    BRANCH_CLASS *actual = firstBranch;
    while (actual != NULL)
    {
        if (actual->getLength() == 0)
        {
            isBranch = true;
            break;
        }
        actual = actual->getNextBranch();
    }
    if (!isBranch)
        return;

    if (actual == firstBranch && actual == lastBranch)
    {
        unsigned int tempoHeight = firstBranch->getHeight();
        delete firstBranch;
        firstBranch = new BRANCH_CLASS(*branch, tempoHeight, this);
        lastBranch = firstBranch;
        firstBranch->setNextBranch(NULL);
        firstBranch->setPreviousBranch(NULL);
    }
    else if (actual == firstBranch)
    {
        BRANCH_CLASS *infBranch = firstBranch->getNextBranch();
        unsigned int cutHeight = firstBranch->getHeight();
        delete firstBranch;
        firstBranch = new BRANCH_CLASS(*branch, cutHeight, this);
        firstBranch->setNextBranch(infBranch);
        firstBranch->setPreviousBranch(NULL);
        infBranch->setPreviousBranch(firstBranch);
    }
    else if (actual == lastBranch)
    {
        BRANCH_CLASS *infBranch = lastBranch->getPreviousBranch();
        unsigned int cutHeight = lastBranch->getHeight();
        delete lastBranch;
        lastBranch = new BRANCH_CLASS(*branch, cutHeight, this);
        lastBranch->setNextBranch(NULL);
        lastBranch->setPreviousBranch(infBranch);
        infBranch->setNextBranch(lastBranch);
    }
    else
    {
        BRANCH_CLASS *nextBranch = actual->getNextBranch();
        BRANCH_CLASS *prevBranch = actual->getPreviousBranch();
        unsigned int cutHeight = actual->getHeight();
        delete actual;
        actual = new BRANCH_CLASS(*branch, cutHeight, this);
        actual->setNextBranch(nextBranch);
        actual->setPreviousBranch(prevBranch);
        prevBranch->setNextBranch(actual);
        nextBranch->setPreviousBranch(actual);
    }
}

GARDEN_CLASS *TREE_CLASS::getGardenPointer()
{
    return treeGarden;
}

BRANCH_CLASS *TREE_CLASS::getBranchPointer(unsigned int height)
{
    BRANCH_CLASS *actual = firstBranch;

    while (actual != NULL)
    {
        if (actual->getHeight() == height)
            return actual;
        actual = actual->getNextBranch();
    }
    return NULL;
}