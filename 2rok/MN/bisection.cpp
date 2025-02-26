//Anhelina Belavezha
#include <cmath>

int sgn(double x) {
        return x > 0 ? 1 : 0;
    }

double findZero (
    double (*f)(double),       //funkcja ktorej zera szukamy fc [a, b]
    double a,                  //lewy koniec przedzialu
    double b,                  //prawy koniec przedzialu 
    int M,                     //maksymalna dowolna liczba wywolan funkcji f
    double eps,                //spodziewana dokladnosc zera
    double delta               //wystarczajacy blad bezwzgledny wyniku
) {
    double fa = f(a);
    double fb = f(b);
    double e = b - a;
    double c;
    double fc;
    double s;

    if(fa == 0) return a;
    if(fb == 0) return b;

    if(f(a) * f(b) <= 0) {                                    //jesli na koncach przedzialu mamy rozne znaki, szybciej pojdzie metoda bisekcji, 
        for(int k = 0; k < M; k++) {                          //po przekroczeniu bardzo malej odleglosci miedzy punktami przechodzimy do metody siecznych
            if((b - a) >= 0.3) {
                e = e / 2.0;
                c = a + e;
                fc = f(c);
                if(fabs(e) < delta || fabs(fc) < eps) break;
                if(sgn(fc) != sgn(fa)) {
                    b = c;
                    fb = fc;
                } 
                else {
                    a = c;
                    fa = fc;
                }
            }
        }

        for(int k = 0; k < M; k++) { 
            s = (b - a) / (fb - fa);
            b = a;
            fb = fa;
            a = a - fa * s;
            fa = f(a);
            if(fabs(fa) < eps || fabs(b - a) < delta) break;
        }
        return a;
    }

    else if(f(a) * f(b) > 0) {                               //jesli na koncach przedzialu mamy te same znaki, nie mozemy korzystac z metody bisekcji     
        for(int k = 0; k < M; k++) {                         //zaczynamy od metody siecznych, potem przyspiesamy sie za pomoca metody bisekcji, 
            s = (b - a) / (fb - fa);                         //po przekroczeniu bardzo malej odleglosci miedzy punktami przechodzimy do metody siecznych z powrotem
            b = a;
            fb = fa;
            a = a - fa * s;
            fa = f(a);
            if(fabs(fa) < eps || fabs(b - a) < delta) break;
        }

        for(int k = 0; k < M; k++) {  
            if((b - a) >= 0.3) {
                e = e / 2.0;
                c = a + e;
                fc = f(c);

                if(fabs(e) < delta || fabs(fc) < eps) break;
                if(sgn(fc) != sgn(fa)) {
                    b = c;
                    fb = fc;
                } 
                else {
                    a = c;
                    fa = fc;
                }
            }
        }

        for(int k = 0; k < M; k++) { 
            s = (b - a) / (fb - fa);
            b = a;
            fb = fa;
            a = a - fa * s;
            fa = f(a);
            if(fabs(fa) < eps || fabs(b - a) < delta) break;
        }
        return a;
    }
    else return a;
} 