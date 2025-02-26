#include "Motolotnia.h"
using namespace std;

Motolotnia::Motolotnia() {}

Motolotnia::~Motolotnia() {}

Motolotnia::Motolotnia(string model_) : Lotnia(model_), Samolot(model_)
{
   Lotnia::model = model_;
}

void Motolotnia::dodajRok()
{
   Lotnia::dodajRok();
}

void Motolotnia::wyswietlWiek() const
{
   cout << "Motolotnia " << Lotnia::model << " ma " << Lotnia::wiek << " lat" << endl;
}

ostream &operator<<(ostream &os, const Motolotnia &s)
{
   return os << "Motolotnia " << s.Lotnia::model;
}

