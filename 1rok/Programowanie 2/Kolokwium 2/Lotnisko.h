#ifndef Lotnisko_H
#define Lotnisko_H

#include "StatekPowietrzny.h"
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Lotnisko
{
private:
   vector<T*> samoloty;

public:
   Lotnisko() {}

   ~Lotnisko()
   {
      samoloty.clear();
   }

   Lotnisko(int n)
   {
      samoloty.resize(n);
      for (int i = 0; i < n; i++)
      {
         samoloty[i] = nullptr;
      }
   }

   T *&operator[](size_t i)
   {
      if (i < 1 || i > samoloty.size())
         throw runtime_error("Nieprawidlowy numer hangaru");
      return samoloty[i - 1];
   }

   void dodajSamolot(const T &samolot)
   {
      samoloty.push_back(samolot);
   }

   template<class T1>
   friend ostream &operator<<(ostream &os, const Lotnisko<T1> &s);

   Lotnisko &operator=(const Lotnisko &s)
   {
      samoloty.clear();
      samoloty.resize(s.samoloty.size());
      for (int i = 0; i < samoloty.size(); i++)
      {
         samoloty[i] = *(s[i]);
      }
      return *this;
   }

   Lotnisko(const Lotnisko &s)
   {
      samoloty.resize(s.samoloty.size());
      for (int i = 0; i < samoloty.size(); i++)
      {
         samoloty[i] = *(s[i]);
      }
   }
};

template<class T>
ostream &operator<<(ostream &os, const Lotnisko<T> &s)
{
   int i = 1;
   for (auto samolot : s.samoloty)
   {
      if (samolot == nullptr)
      {
         os << "Pusty hangar" << endl;
      }
      else
      {
         os << i << " ";
         os << *samolot;
      }
      i++;
   }
   return os;
}
#endif
