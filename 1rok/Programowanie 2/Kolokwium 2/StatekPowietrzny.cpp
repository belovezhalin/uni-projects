#include "StatekPowietrzny.h"
using namespace std;

StatekPowietrzny::StatekPowietrzny() : wiek(0) {}

StatekPowietrzny::~StatekPowietrzny() {}

StatekPowietrzny::StatekPowietrzny(string nazwa) : wiek(0), model(nazwa) {}

void StatekPowietrzny::dodajRok() {wiek++;}

StatekPowietrzny::StatekPowietrzny(const StatekPowietrzny &s) : wiek(s.wiek), model(s.model) {}

StatekPowietrzny &StatekPowietrzny::operator=(const StatekPowietrzny &s) {
   this->wiek = s.wiek;
   this->model = s.model;
   return *this;
}
