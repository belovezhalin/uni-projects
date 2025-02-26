#ifndef Lotnia_H
#define Lotnia_H

#include "StatekPowietrzny.h"
#include <iostream>
#include <string>
using namespace std;

class Lotnia : public virtual StatekPowietrzny
{
public:
   Lotnia();
   ~Lotnia();
   Lotnia(string nazwa);
   void wyswietlWiek() const override;
   friend ostream &operator<<(ostream &os, const Lotnia &s);
};

ostream &operator<<(ostream &os, const Lotnia &s);

#endif
