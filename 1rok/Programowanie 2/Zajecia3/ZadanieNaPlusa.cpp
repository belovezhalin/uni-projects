#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>
using namespace std;

void coutf(const char *symbol, ...) {
   va_list ap;
   va_start(ap, symbol);
   int i = 0;
   while ((symbol[i++]) != '\0') {
      if (symbol[i] == '%' && symbol[i + 1] != '%') {
         if (symbol[i + 1] != '\0' && symbol[i + 1] != ' ') {
            i++;
            if (symbol[i] == 'd') cout << va_arg(ap, int);
            else if (symbol[i] == 'f') cout << va_arg(ap, double);
            else if (symbol[i] == 'c') cout << va_arg(ap, char);
            else if (symbol[i] == 's') cout << va_arg(ap, char *);}}
      else if (symbol[i] == '%%') {
         if (symbol[i + 1] != '\0') {
            i++;
            if (symbol[i] == '%') cout << '%';}}
      else cout << symbol[i];
   }
   va_end(ap);
}

int main()
{
   coutf(" ala %s ma %d kota %%\n", "chyba", 3);
}