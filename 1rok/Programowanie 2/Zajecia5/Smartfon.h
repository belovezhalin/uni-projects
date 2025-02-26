#include "UrzadzenieNaBaterie.h"
#include "TelefonKomorkowy.h"
#include "AparatCyfrowy.h"
#include "OdtwarzaczMultimedialny.h"

#ifndef __SMARTFON_H__
#define __SMARTFON_H__

class Smartfon : public TK, public AC, public OM
{
private:
     bool klawiatura;
     unsigned taktowanieProcesora;

public:
     Smartfon(unsigned ile, bool k = false, unsigned t = 1000) : UNB(ile), TK(ile), AC(ile), OM(ile)
     {
          klawiatura = k;
          taktowanieProcesora = t;
          printf("Tworze smartfon\n");
     }

     ~Smartfon()
     {
          printf("Niszcze smartfon\n");
     }

     void przezentuj()
     {
          printf("Jestem smartfonem\n");
     }

     bool getKlawiatura()
     {
          return klawiatura;
     }

     unsigned getTaktowanieProcesora()
     {
          return taktowanieProcesora;
     }
};

#endif
