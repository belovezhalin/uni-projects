#include "Game.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

Game::Game() : mynumsteps(0), mycurrenttable(nullptr) {}

void Game::Run() {
   char initialTable[100];
   cout << "Witam w grze Game of Life! Wprowadz tablice:" << endl;
   fgets(initialTable, sizeof(initialTable), stdin);

   initialTable[strlen(initialTable) - 1] = char(0);
   mycurrenttable = mydatainterface.LoadTable(initialTable);

   cout << "Wprowadz ilosc krokow:" << endl;
   cin >> mynumsteps;

   for (int i = 1; i <= mynumsteps; i++) {
      Advance();
      string filename = "tablica" + to_string(i) + ".txt";
      mydatainterface.SaveTable(mycurrenttable, filename.c_str());
   }
}

void Game::Advance() {
   Table *nextTable = new Table(*mycurrenttable);
   for (int x = 0; x < mycurrenttable->GetWidth(); x++) {
      for (int y = 0; y < mycurrenttable->GetHeight(); y++) {
         int liveNeighbors = mycurrenttable->CountLiveNeighbors(x, y);

         bool nextState = false;
         if(mycurrenttable->Get(x, y)) {
            if (liveNeighbors == 2 || liveNeighbors == 3) {
               nextState = true;
            }
         }
         else {
            if (liveNeighbors == 3) {
               nextState = true;
            }
         }
         nextTable->Set(x, y, nextState);
      }
   }
   free(mycurrenttable);
   mycurrenttable = nextTable;
}
