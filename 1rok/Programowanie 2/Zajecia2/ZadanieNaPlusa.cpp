#include <iostream>
#include <cstdarg>
using namespace std;

int dodajint (const int ilosc, ...) {
    int liczba = 0;
    int suma = 0;

    va_list ap;
    va_start(ap, ilosc);

    for (int i = 0; i < ilosc; i++) {
        liczba = va_arg(ap, int);
        suma += liczba;
    }
    return suma;
    va_end(ap);
}

double dodajdouble(const double ilosc, ...) {
    double liczba = 0;
    double suma = 0;

    va_list ap;
    va_start(ap, ilosc);

    for (int i = 0; i < ilosc; i++) {
        liczba = va_arg(ap, double);
        suma += liczba;
    }
    return suma;
    va_end(ap);
}

int main () {
    cout << endl << "Suma intow 2, 1, 5, 4 wynosi " << dodajint(4, 2, 1, 5, 4) << endl;
    cout << "Suma doublow 2.1, 4.5, 6.7 wynosi " << dodajdouble(3, 2.1, 4.5, 6.7) << endl << endl;

    return 0;
}