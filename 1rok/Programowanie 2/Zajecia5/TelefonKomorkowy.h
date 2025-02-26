#include <cstdio>
#include "UrzadzenieNaBaterie.h"

#ifndef __TELEFON_KOMORKOWY_H__
#define __TELEFON_KOMORKOWY_H__

class TK : public virtual UNB
{
private:
     bool dotykowy;
     bool przegladarka;

public:
     TK(unsigned ile, bool d = true, bool p = true) : UNB(ile)
     {
          dotykowy = d;
          przegladarka = p;
          printf("Tworze TK\n");
     }

     ~TK()
     {
          printf("Niszcze TK\n");
     }

     void przezentuj()
     {
          printf("Jestem telefonem\n");
     }

     bool getDotykowy()
     {
          return dotykowy;
     }

     bool getPrzegladarka()
     {
          return przegladarka;
     }
};

#endif
