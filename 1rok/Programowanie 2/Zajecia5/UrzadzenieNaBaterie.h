#include <cstdio>
#include "Bateria.h"

#ifndef __UNB__H__
#define __UNB__H__

class UNB
{
private:
  Bateria **pojemnik;
  unsigned ile;
  bool onoff;
  int ileZuzywa;

public:
  UNB(unsigned i, unsigned z = 5) : ile(1), onoff(false)
  {
    if (i == 0)
      printf("Urz�denie nie mo�e nie posiada� baterii. Tworz� obiekt o pojemniku na jedn� bateri�");
    pojemnik = new Bateria *[i];
    ile = i;
    ileZuzywa = z;
    for (unsigned j = 0; j < i; j++)
      pojemnik[j] = 0;
    printf("Tworze UNB: %d\n", ile);
  }

  ~UNB()
  {
    delete[] pojemnik;
    printf("Niszcze UNB: %d\n", ile);
  }

  void wloz(Bateria *b, unsigned i)
  {
    if (i > ile - 1)
    {
      printf("Nie ma baterii o tym numerze");
      return;
    }
    pojemnik[i] = b;
  }

  Bateria *wyjmij(unsigned i)
  {
    if (i > ile - 1)
    {
      printf("Nie ma baterii o tym numerze");
      return 0;
    }
    Bateria *b = pojemnik[i];
    pojemnik[i] = 0;
    return b;
  }

  void wlacz() { onoff = true; }

  void wylacz() { onoff = false; }

  bool stan() { return onoff; }

  bool czyKomplet()
  {
    for (unsigned i = 0; i < ile; i++)
      if (pojemnik[i] == 0)
        return false;
    return true;
  }

  void rozladuj(unsigned e1)
  {
    unsigned s = 0;
    for (unsigned i = 0; i < ile; i++)
      if (pojemnik[i] != 0)
        s += pojemnik[i]->getStanNaladowania();
    unsigned e2;
    if (s > e1)
      e2 = e1;
    else
      e2 = s;
    for (unsigned j = 0; j < e2; j++)
    {
      if (pojemnik[j % ile] != 0)
      {
        if (pojemnik[j % ile]->getStanNaladowania() != 0)
          pojemnik[j % ile]->rozladuj(1);
      }
      else
        e2++;
    }
  }

  int getIleZuzywa() { return ileZuzywa; }
};

#endif
