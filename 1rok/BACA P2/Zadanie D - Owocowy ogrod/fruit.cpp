// Anhelina Belavezha
#include <iostream>
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"
/////////////////////////////////////////////////////////////getters i setters
unsigned int FRUIT_CLASS::getLength()
{
    return fruitBranchLength;
}

void FRUIT_CLASS::setFruitBranchLength(unsigned int length)
{
    fruitBranchLength = length;
}

unsigned int FRUIT_CLASS::getWeight()
{
    return fruitWeight;
}

void FRUIT_CLASS::setFruitWeight(unsigned int weight)
{
    fruitWeight = weight;
}

BRANCH_CLASS *FRUIT_CLASS::getFruitBranch()
{
    return fruitBranch;
}

void FRUIT_CLASS::setFruitBranch(BRANCH_CLASS *branch)
{
    fruitBranch = branch;
}

FRUIT_CLASS *FRUIT_CLASS::getNextFruit()
{
    return next;
}

void FRUIT_CLASS::setNextFruit(FRUIT_CLASS *nextFruit)
{
    next = nextFruit;
}

FRUIT_CLASS *FRUIT_CLASS::getPreviousFruit()
{
    return previous;
}

void FRUIT_CLASS::setPreviousFruit(FRUIT_CLASS *previousFruit)
{
    previous = previousFruit;
}
////////////////////////////////////////////////////////konstruktory i destruktor
FRUIT_CLASS::FRUIT_CLASS()
{
    fruitBranchLength = 0;
    fruitWeight = 0;
    fruitBranch = NULL;
    next = NULL;
    previous = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS *fruitBranch, unsigned int fruitWeight, unsigned int fruitBranchLength)
{
    this->fruitBranch = fruitBranch;
    this->fruitWeight = fruitWeight;
    this->fruitBranchLength = fruitBranchLength;

    if (fruitBranch != NULL)
    {
        fruitBranch->setFruitsNumber(fruitBranch->getFruitsNumber() + 1);
        fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() + fruitWeight);
        if (fruitBranch->getTreePointer() != NULL)
        {
            fruitBranch->getTreePointer()->setFruitsNumber(fruitBranch->getTreePointer()->getFruitsNumber() + 1);
            fruitBranch->getTreePointer()->setFruitsWeight(fruitBranch->getTreePointer()->getFruitsWeight() + fruitWeight);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL)
            {
                fruitBranch->getTreePointer()->getGardenPointer()->setFruitsNumber(fruitBranch->getTreePointer()->getGardenPointer()->getFruitsNumber() + 1);
                fruitBranch->getTreePointer()->getGardenPointer()->setFruitsWeight(fruitBranch->getTreePointer()->getGardenPointer()->getFruitsWeight() + fruitWeight);
            }
        }
    }

    this->next = NULL;
    this->previous = NULL;
}

FRUIT_CLASS::~FRUIT_CLASS()
{
    if (fruitBranch != NULL)
    {
        fruitBranch->setFruitsNumber(fruitBranch->getFruitsNumber() - 1);
        fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() - fruitWeight);

        if (fruitBranch->getBranchTree() != NULL)
        {
            fruitBranch->getBranchTree()->setFruitsNumber(fruitBranch->getBranchTree()->getFruitsNumber() - 1);
            fruitBranch->getBranchTree()->setFruitsWeight(fruitBranch->getBranchTree()->getFruitsWeight() - fruitWeight);

            if (fruitBranch->getBranchTree()->getTreeGarden() != NULL)
            {
                fruitBranch->getBranchTree()->getTreeGarden()->setFruitsNumber(fruitBranch->getBranchTree()->getTreeGarden()->getFruitsNumber() - 1);
                fruitBranch->getBranchTree()->getTreeGarden()->setFruitsWeight(fruitBranch->getBranchTree()->getTreeGarden()->getFruitsWeight() - fruitWeight);
            }
        }
    }
}
///////////////////////////////////////////////////////////////konstruktor kopiujacy
FRUIT_CLASS::FRUIT_CLASS(FRUIT_CLASS &copy, BRANCH_CLASS *fruitBranch)
{
    this->fruitBranch = fruitBranch;
    this->fruitWeight = copy.fruitWeight;
    this->fruitBranchLength = copy.fruitBranchLength;

    if (fruitBranch != NULL)
    {
        fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() + this->fruitWeight);
        fruitBranch->setFruitsNumber(fruitBranch->getFruitsNumber() + 1);
        if (fruitBranch->getTreePointer() != NULL)
        {
            fruitBranch->getTreePointer()->setFruitsWeight(fruitBranch->getTreePointer()->getFruitsWeight() + this->fruitWeight);
            fruitBranch->getTreePointer()->setFruitsNumber(fruitBranch->getTreePointer()->getFruitsNumber() + 1);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL)
            {
                fruitBranch->getTreePointer()->getGardenPointer()->setFruitsWeight(fruitBranch->getTreePointer()->getGardenPointer()->getFruitsWeight() + this->fruitWeight);
                fruitBranch->getTreePointer()->getGardenPointer()->setFruitsNumber(fruitBranch->getTreePointer()->getGardenPointer()->getFruitsNumber() + 1);
            }
        }
    }
    next = NULL;
    previous = NULL;
}
///////////////////////////////////////////////////////////////metody
void FRUIT_CLASS::growthFruit()
{
    fruitWeight += 1;
    if (fruitBranch != NULL)
    {
        fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() + 1);

        if (fruitBranch->getBranchTree() != NULL)
        {
            fruitBranch->getBranchTree()->setFruitsWeight(fruitBranch->getBranchTree()->getFruitsWeight() + 1);

            if (fruitBranch->getBranchTree()->getTreeGarden() != NULL)
            {
                fruitBranch->getBranchTree()->getTreeGarden()->setFruitsWeight(fruitBranch->getBranchTree()->getTreeGarden()->getFruitsWeight() + 1);
            }
        }
    }
}

void FRUIT_CLASS::fadeFruit()
{
    if (fruitWeight > 0)
    {
        fruitWeight -= 1;
        if (fruitBranch != NULL)
        {
            fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() - 1);

            if (fruitBranch->getBranchTree() != NULL)
            {
                fruitBranch->getBranchTree()->setFruitsWeight(fruitBranch->getBranchTree()->getFruitsWeight() - 1);

                if (fruitBranch->getBranchTree()->getTreeGarden() != NULL)
                {
                    fruitBranch->getBranchTree()->getTreeGarden()->setFruitsWeight(fruitBranch->getBranchTree()->getTreeGarden()->getFruitsWeight() - 1);
                }
            }
        }
    }
}

void FRUIT_CLASS::pluckFruit()
{
    if (fruitBranch != NULL)
    {
        fruitBranch->setFruitsWeight(fruitBranch->getFruitsWeight() - fruitWeight);

        if (fruitBranch->getBranchTree() != NULL)
        {
            fruitBranch->getBranchTree()->setFruitsWeight(fruitBranch->getBranchTree()->getFruitsWeight() - fruitWeight);

            if (fruitBranch->getBranchTree()->getTreeGarden() != NULL)
            {
                fruitBranch->getBranchTree()->getTreeGarden()->setFruitsWeight(fruitBranch->getBranchTree()->getTreeGarden()->getFruitsWeight() - fruitWeight);
            }
        }
    }
    fruitWeight = 0;
}

BRANCH_CLASS *FRUIT_CLASS::getBranchPointer()
{
    return fruitBranch;
}
