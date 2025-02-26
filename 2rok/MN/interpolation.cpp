//Anhelina Belavezha
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : factorial(n - 1) * n;
}

vector<double> Interpolation(vector<double>& X, vector<double>& Y, vector<double>& Y1, vector<double>& Ynext) {
    vector<double> coefficient(Y.size());                                        //przechowuje wspolczynniki interpolacji hermitea
    coefficient[0] = Y1[0];

    for(int i = 1; i < Y1.size(); i ++) {
        for(int j = 0; j < Y1.size() - i; j ++) {
            if(X[j] == X[j + i]) {
                Y1[j] = Y[Ynext[j] + i] / factorial(i);
            }
            else {
                Y1[j] = (Y1[j + 1] - Y1[j]) / (X[j + i] - X[j]);
            }
        }
        coefficient[i] = Y1[0];
    }
    return coefficient;
}

double Hermitea(vector<double>& X, vector<double>& interpolation, double t) {
    double results = *(interpolation.end() - 1);
    for(int i = interpolation.size() - 2; i >= 0; i --) {
        results *= t - X[i];
        results += interpolation[i];
    }
    return results;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<double> X(M);
    vector<double> Y(M);
    vector<double> T(N);
    for(int i = 0; i < M; i ++) {
        cin >> X[i];
    }

    for(int i = 0; i < M; i ++) {
        cin >> Y[i];
    }
    
    for(int i = 0; i < N; i ++) {
        cin >> T[i];
    }

    vector<double> Y1(M);                      //dla przypadkow powtorzenia wezlow
    vector<double> Ynext(M);              
    Y1[0] = Y[0];
    Ynext[0] = 0;

    for(int i = 1; i < M; i ++) {
        if(X[i] == X[i - 1]) {
            Y1[i] = Y1[i - 1];        //kopiujemy dla powtorzen
            Ynext[i] = Ynext[i - 1];
        }
        else {
            Y1[i] = Y[i];
            Ynext[i] = i;
        }
    }

    vector<double> interpolation = Interpolation(X, Y, Y1, Ynext);

    for (int i = 0; i < interpolation.size(); i ++) {
        double results = interpolation[i];
        cout << fixed << setprecision(17) << results << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i ++) {
        double results = Hermitea(X, interpolation, T[i]);
        cout << fixed << setprecision(17) << results << " ";
    }

    return 0;
}

