#include "Lotnia.h"
using namespace std;

Lotnia::Lotnia() {}

Lotnia::~Lotnia() {}

Lotnia::Lotnia(string nazwa) : StatekPowietrzny(nazwa) {}

void Lotnia::wyswietlWiek() const
{
   cout << *this << " ma " << wiek << " lat" << endl;
}

ostream &operator<<(ostream &os, const Lotnia &s)
{
   return os << "Lotnia " << s.model << endl;
}