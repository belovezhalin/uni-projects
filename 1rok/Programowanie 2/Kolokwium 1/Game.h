#ifndef GAME_H
#define GAME_H

#include "Table.h"
#include "DataInterface.h"

class Game {
public:
   Game();
   void Run();

private:
   int mynumsteps;
   Table *mycurrenttable;
   DataInterface mydatainterface;
   void Advance();
};

#endif
