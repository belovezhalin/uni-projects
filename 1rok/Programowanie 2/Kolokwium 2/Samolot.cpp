#include "Samolot.h"
using namespace std;

Samolot::Samolot() : StatekPowietrzny() {}

Samolot::~Samolot() {}

Samolot::Samolot(string nazwa) : StatekPowietrzny(nazwa) {}

void Samolot::wyswietlWiek() const
{
   cout << *this << " ma " << wiek << " lat" << endl;
}

ostream &operator<<(ostream &os, const Samolot &s)
{
   return os << "Samolot " << s.model << endl;
}
