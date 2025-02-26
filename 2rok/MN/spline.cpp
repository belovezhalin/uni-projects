//Anhelina Belavezha
#include "source.h"
#include <cmath>
#include <iostream>
using namespace std;

spline::spline(int n) : n(n) {
    h = new double[n]{0};
    x = new double[n]{0};
    y = new double[n]{0};
    z = new double[n]{0};
}

spline::~spline() {
    delete[] h;
    delete[] x;
    delete[] y;
    delete[] z;
}

void spline::set_points(double* x, double* y) {
    for(int i = 0; i < n; i ++) {
        this->x[i] = x[i];
        this->y[i] = y[i];
    }
    calc();
}

double spline::operator()(double z) const {
    int i;
    for(i = 0; i < n - 1; i ++) {
        if(z < x[i + 1]) {
            break;
        }
    }
    if(i == n - 1) {
        i = n - 2;  
    }
    return (y[i] + (z - x[i]) * (getC(i) + (z - x[i]) * (getB(i) + (z - x[i]) * getA(i))));
}

double spline::getA(int i) const {
    return ((z[i + 1] - z[i]) / (6 * h[i]));
}

double spline::getB(int i) const {
    return (z[i] / 2);
}

double spline::getC(int i) const {
    return ((y[i + 1] - y[i]) / h[i] - (z[i + 1] + 2 * z[i]) * h[i] / 6);
}

void spline::calc() {
    double* a = new double[n]{0};
    double* b = new double[n]{0};
    double* c = new double[n]{0};

    for(int i = 0; i < n - 1; i ++) {
        h[i] = x[i + 1] - x[i];
        a[i] = 6 * (y[i + 1] - y[i]) / h[i];
    }

    b[1] = 2 * (h[0] + h[1]);
    c[1] = a[1] - a[0];

    for(int i = 2; i < n - 1; i++) {
        b[i] = 2 * (h[i - 1] + h[i]) - (h[i - 1] * h[i - 1]) / b[i - 1];
        c[i] = a[i] - a[i - 1] - (h[i - 1] * c[i - 1]) / b[i - 1];
    }

    z[n - 1] = 0;  

    for(int i = n - 2; i > 0; i--) {
        z[i] = (c[i] - h[i] * z[i + 1]) / b[i];
    }
    
    z[0] = 0;  

    delete[] a;
    delete[] b;
    delete[] c;
}
/*
int main() {
    cout.precision(15);
    cout << fixed;

    int size = 6; 
    double X[] = {0, 0.2, 0.4, 0.6, 0.8, 1};
    double Y[] = {-3, -2.56, -2.04, -1.44, -0.76, 0};

    spline s(size);
    s.set_points(X, Y);    

    for(int i = 0; i < size - 1; i++) {
        cout << s(X[i]) << "  " << s(X[i] + 0.02) << "  " << s(X[i] + 0.07) << endl;
    }

    return 0;
}
*/