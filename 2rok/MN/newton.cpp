//Anhelina Belavezha
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef void (*FuncPointer)(const double* x, double* y, double* Df); 

void printVector(const double* x, unsigned N) {
  for(unsigned i = 0; i < N; ++i)
    printf("%17.17f ", x[i]);
  printf("\n");
}

double multiplication(double x1, double x2, double x3, double x4) {         //obliczenie determinantu lub mnozenie dwoch macierzy
    return x1 * x2 - x3 * x4;
}

int findCurve(FuncPointer f, double* x, unsigned k, double h) {
    int Q;
    double y[2];
    double Df[6];

    for(int i = 1; i <= k; i++) {
        bool isfound = false;
        double X[3] = {x[0], x[1], x[2] + i * h};
        f(X, y, Df);
        Q = 10000;

        while(Q-- > 0) {
            if(multiplication(Df[0],Df[4], Df[1],Df[3]) != 0) {
                X[0] -= (multiplication(Df[4], y[0], Df[1], y[1])) / multiplication(Df[0], Df[4], Df[1], Df[3]);
                X[1] -= (multiplication(Df[0], y[1], Df[3], y[0])) / multiplication(Df[0], Df[4], Df[1], Df[3]);
                f(X, y, Df);

                if((fabs(y[0]) <= 1e-14) && (fabs(y[1]) <= 1e-14)) {         //porownanie z tolerancja absolutna
                    printVector(X, 3);
                    isfound = true;
                    break;
                }
            }
            else return i;                                                  //zwracanie indeksu i, dla ktorego nastapil problem 
        }  
        if(isfound == false) return i;
    }
    return 0;
}

int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2) {
    int Q;
    double y[1];
    double Df[3];

    for(int i1 = 1; i1 <= k1; i1++) {
        for(int i2 = 1; i2 <= k2; i2++) {
            double X[3] = {x[0], x[1] + i1 * h1, x[2] + i2 * h2};
            f(X, y, Df);
            Q = 10000;

            while(Q-- > 0) {
                if(multiplication(Df[0], 1, 0, 0) != 0) {
                    X[0] -= (y[0] / multiplication(Df[0], 1, 0, 0));
                    f(X, y, Df);

                    if(fabs(y[0]) <= 1e-14) {
                        printVector(X, 3);
                        break;
                    }
                }
                else return i1 * k1 + i2;    
            }
        }
        cout << endl;
    }
    return 0;
}

int findFixedPoints(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2) {
    int Q;
    double y[2];
    double Df[8];

    for(int i1 = 1; i1 <= k1; i1++) {
        for(int i2 = 1; i2 <= k2; i2++) {
            double X[4] = {x[0], x[1], x[2] + i1 * h1, x[3] + i2 * h2};
            f(X, y, Df);
            Q = 10000;

            while(Q-- > 0) {
                Df[0] -= 1;
                Df[5] -= 1;

                if(multiplication(Df[0], Df[5], Df[1], Df[4]) != 0) {
                    double a0 = y[0] - X[0];
                    double a1 = y[1] - X[1];

                    X[0] -= (multiplication(Df[5], a0, Df[1], a1)) / multiplication(Df[0], Df[5], Df[1], Df[4]);
                    X[1] -= (multiplication(Df[0], a1, Df[4], a0)) / multiplication(Df[0], Df[5], Df[1], Df[4]);
                    f(X, y, Df);

                    if((fabs(a0) <= 1e-14) && (fabs(a1) <= 1e-14)) {
                        printVector(X, 4);
                        break;
                    }
                }
                else return i1 * k1 + i2; 
            }
        }
        cout << endl;
    }
    return 0;
}
/*
void implicitSurface(const double* x, double* y, double* Df){
    // funkcja dana jest wzorem f(a,b,c) = (a+b+c)/(a^2+b^2+c^2)-1
    // zmienne pomocnicze
    const double n = x[0]*x[0] + x[1]*x[1] + x[2]*x[2];
    const double s = x[0] + x[1] + x[2];
    
    // obliczam wartosc funkcji
    *y = s/n - 1.;
    
    //obliczam pierwszy i jedyny wiersz macierzy
    const double r = 1./n;
    const double r2 = 2.*(*y)*r;
    Df[0] = r - x[0]*r2;
    Df[1] = r - x[1]*r2;
    Df[2] = r - x[2]*r2;
  }

  int main(){
    double x[3] = {0.25*(1.+sqrt(5.)),0.25*(1.-sqrt(5.)),0.5};
    findSurface(implicitSurface,x,4,4,1./32,1./32);
    return 0;
  }
*/
/*
void henon(const double* x, double* y, double* Df){
    // funkcja dana jest wzorem henon(x,y,a,b) = (1+y-a*x^2,b*x)
    const double x2 = x[0]*x[0];
    
    y[0] = 1 + x[1] - x[2]*x2;
    y[1] = x[3]*x[0];
    
    //obliczam pierwszy wiersz macierzy
    Df[0] = -2*x[2]*x[0];
    Df[1] = 1.;
    Df[2] = -x2;
    Df[3] = 0.;
    
    //obliczam drugi wiersz macierzy
    Df[4] = x[3];
    Df[5] = 0.;
    Df[6] = 0.;
    Df[7] = x[0];
  }

  int main(){
    double x[4] = {-1.2807764064044151, -0.6403882032022076, 1.0000000000000000, 0.50000000000000000};
    findFixedPoints(henon,x,4,4,1./16,1./16);
    return 0;
  }
*/