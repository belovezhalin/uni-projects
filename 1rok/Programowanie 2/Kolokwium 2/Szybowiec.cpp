#include "Szybowiec.h"
using namespace std;

Szybowiec::Szybowiec() {}

Szybowiec::~Szybowiec() {}

Szybowiec::Szybowiec(string nazwa) : StatekPowietrzny(nazwa) {}

void Szybowiec::wyswietlWiek() const
{
   cout << *this << " ma " << wiek << " lat" << endl;
}

ostream &operator<<(ostream &os, const Szybowiec &s)
{
   return os << "Szybowiec " << s.model << endl;
}
