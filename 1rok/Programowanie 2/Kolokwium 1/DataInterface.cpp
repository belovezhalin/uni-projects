#include "DataInterface.h"
#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

Table *DataInterface::LoadTable(const char *str) const {
   FILE *fp = fopen(str, "r");
   if (fp == nullptr) {
      printf("Can't open file");
      exit(0);
   }

   char line[100];
   Table *table = new Table();

   while (fgets(line, sizeof(line), fp) != NULL) {
      table->AddLine(line);
   }
   
   fclose(fp);
   return table;
}

void DataInterface::SaveTable(const Table *table, const char *filename) const {                         //przepisanie do pliku tekstowego
   ofstream output(filename);  
   FILE *fp = fopen(filename, "w");
   for (int x = 0; x < table->GetHeight(); x++) {
      for (int y = 0; y < table->GetWidth(); y++) {
         if (table->Get(x, y)) {
            fprintf(fp, "X");
         }
         else
            fprintf(fp, "_"); 
      }
      fprintf(fp, "\n");
   }
   output.close();
}