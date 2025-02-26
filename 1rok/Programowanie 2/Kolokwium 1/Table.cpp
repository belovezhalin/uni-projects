#include "Table.h"
#include <cstring>
#include <stdlib.h>

Table::Table() {                                                                //konstruktory i destruktor 
   mywidth = 0;
   myheight = 0;
   mycells = nullptr;
}

Table::Table(const Table &t) {
   mywidth = t.mywidth;
   myheight = t.myheight;
   mycells = (bool **)malloc(sizeof(bool *) * mywidth);

   for (int i = 0; i < myheight; i++) {
      mycells[i] = (bool *)malloc(sizeof(bool) * myheight);
      for (int j = 0; j < mywidth; j++) {
         mycells[i][j] = t.mycells[i][j];
      }
   }
}

Table::~Table() {
   for (int x = 0; x < myheight; x++) {
      free(mycells[x]);
      mycells[x] = nullptr;
   }
   free(mycells);
   mycells = nullptr;
}
/*
Table& Table::operator=(const Table& t) {
    if (this == &t) {
        return *this;
    }

    for (int x = 0; x < myheight; x++) {
        free(mycells[x]);
        mycells[x] = nullptr;
    }

    free(mycells);
    mycells = nullptr;

    mywidth = t.mywidth;
    myheight = t.myheight;
    mycells = (bool**)malloc(sizeof(bool*) * mywidth);

    for (int i = 0; i < myheight; i++) {
        mycells[i] = (bool**)malloc(sizeof(bool) * myheight);
        for (int j = 0; j < mywidth; j++) {
            mycells[i][j] = t.mycells[i][j];
        }
    }
    return *this;
}
*/
bool Table::Get(int x, int y) const {                                                 //gettery i settery
   if (x < 0 || x >= myheight || y < 0 || y >= mywidth) {
      return false;
   }
   else
      return mycells[x][y];
}

void Table::Set(int x, int y, bool value) {
   if (x >= 0 && x < myheight && y >= 0 && y < mywidth) {
      mycells[x][y] = value;
   }
}

int Table::GetWidth() const {
   return mywidth;
}

int Table::GetHeight() const {
   return myheight;
}

int Table::CountLiveNeighbors(int x, int y) const {                                   //zliczamy ilosc zywych sasiedzi
   int count = 0;
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i != 0 || j != 0) {
            if (Get(x + i, y + j))
               count++;
         }
      }
   }
   return count;
}

void Table::AddLine(char *str) {
   mycells = (bool **)realloc(mycells, (myheight + 1) * sizeof(bool *));
   myheight++;
   if (myheight == 1) {
      mywidth = strlen(str);
   }
   mycells[myheight - 1] = new bool[mywidth];
   for (int i = 0; i < mywidth; i++) {
      if (str[i] == 'X')
         mycells[myheight - 1][i] = 1;
   }
   return;
}
