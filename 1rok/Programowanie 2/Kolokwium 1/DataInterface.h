#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include "Table.h"
#include <string>

class DataInterface {
public:
   Table *LoadTable(const char *str) const;
   void SaveTable(const Table *table, const char *filename) const;
};

#endif