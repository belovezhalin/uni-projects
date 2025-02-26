#ifndef Samolot_H
#define Samolot_H

#include "StatekPowietrzny.h"
#include <iostream>
#include <string>
using namespace std;

class Samolot : public virtual StatekPowietrzny
{
public:
   Samolot();
   ~Samolot();
   Samolot(string nazwa);
   void wyswietlWiek() const override;
   friend ostream &operator<<(ostream &os, const Samolot &s);
};

ostream &operator<<(ostream &os, const Samolot &s);

#endif 
