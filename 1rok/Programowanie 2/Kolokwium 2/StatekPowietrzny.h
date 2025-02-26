#ifndef StatekPowietrzny_H
#define StatekPowietrzny_H

#include <iostream>
#include <string>
using namespace std;

class StatekPowietrzny
{
protected:
   int wiek;
   string model;

public:
   StatekPowietrzny();
   virtual ~StatekPowietrzny();
   StatekPowietrzny(string nazwa);
   void dodajRok();
   virtual void wyswietlWiek() const = 0;
   StatekPowietrzny(const StatekPowietrzny &s);
   StatekPowietrzny &operator=(const StatekPowietrzny &s);
};

#endif 
