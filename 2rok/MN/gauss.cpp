//Anhelina Belavezha
#include "vectalg.h"
#include <iostream>
using namespace std;

void Gauss(Matrix& newA, Vector& newV, int* perm, double* norm) {                    //metoda eliminacji Gaussa
    for(int i = 0; i < newA.size() - 1; i++) {
        int rownumber = 0;
        double max = 0;
        for(int k = i; k < newA.size(); k++) {                                       //szukamy wierz z najwieksza norma wzgledna w kolumnie 
            double temp = abs(newA(perm[k], i) / norm[perm[k]]);
            if(max < temp) {
                max = temp; 
                rownumber = k;
            }
        }
        
        swap(perm[rownumber], perm[i]);                                              //wybor elementu glownego

        for(int j = i + 1; j < newA.size(); j++) {
            double coefficient = newA(perm[j], i) / newA(perm[i], i);

            Matrix::iterator i1 = newA.begin();                                      //odejmowanie wierszy
            Matrix::iterator i2 = i1;
            i1 += newA.size() * perm[i] + i;
            i2 += newA.size() * perm[j] + i;
            for(int k = i; k < newA.size(); k++) {
                *i2 = *i2 - *i1 * coefficient;
                i1++;
                i2++;
            }

            newV[perm[j]] -= newV[perm[i]] * coefficient;
        }
    }
}

Vector* Add(Vector& x, Vector& y) {                                                  //dodawanie wektorow
    if(x.size() == y.size()) {
        Vector* result = new Vector(x.size());
        Vector::iterator iterator = (*result).begin();

        for(int i = 0; i < x.size(); i++) {
            *iterator = x[i] + y[i];
            iterator++;
        }
        return result;
    }
}

Vector solveEquations(const Matrix& A, const Vector& b, double eps) {
    Matrix* newA = new Matrix(A);
    Vector* newV = new Vector(b);

    int perm[A.size()];
    for(int i = 0; i < A.size(); i++) {
        perm[i] = i;                                                                //tablica permutacji
    }
    
    double* norm = new double[A.size()];                                            //wyznaczamy norme macierzy A
    for(int i = 0; i < A.size(); i++) {
        norm[i] = 0;
        for(int j = 0; j < A.size(); j++) {
            double temp = abs(A(i, j));
            if(norm[i] < temp) {
                norm[i] = temp;
            }
        }
    }

    Gauss(*newA, *newV, perm, norm);
    Vector* x = new Vector(A.size());
    Vector::iterator iterator = x->end() - 1;

    for(int i = A.size() - 1; i >= 0; i--) {
        double temp = 0; 
        for(int j = i + 1; j < A.size(); j++) {
            temp += (*newA)(perm[i], j) * (*x)[j];
        }

        *iterator = ((*newV)[perm[i]] - temp) / (*newA)(perm[i], i);
        iterator--;
    }

    Vector result = residual_vector(A, b, *x);
    
    while(result.max_norm() >= eps) {                                               //iteracyjnie poprawiamy wynik       
        Vector newiteration = solveEquations(A, result, eps);
        x = Add(*x, newiteration);
        result = residual_vector(A, b, *x);
    }

    return *x;
}

/*
int main(){
    cout.precision(17);
    int n = 0;
    double eps = 0;

    // wczytywanie danych
    cin >> n;
    Matrix a(n);
    Vector b(n);
    cin >> a >> b >> eps;

    Vector x = solveEquations(a, b, eps);

    auto residual = residual_vector(a, b, x);
    cout << "rozwiazanie = " << x << endl;
    cout << "rezydualny = " << residual << endl;
    cout << "blad = " << residual.max_norm()
         << " limit = " << eps << endl ;
    cout << "Test " << (residual.max_norm() < eps ? "":"nie ") << "zaliczony" << endl; 
    return 0;
}	
*/