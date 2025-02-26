#include <iostream>
using namespace std;

class ThreeDArray {
private:
    int d1, d2;
    int* d3;
    double*** data;

public:
    ThreeDArray() : d1(0), d2(0), d3(nullptr), data(nullptr) {}                            //Konstruktor domyślny
    
    ThreeDArray(int d1, int d2, int* d3) : d1(d1), d2(d2), d3(new int[d2]), data(new double** [d1]) {   //Konstruktor tworzący tablicę o podanych pojemnościach wypełnioną zerami
        for (int i = 0; i < d1; i++) {
            data[i] = new double* [d2];
            for (int j = 0; j < d2; j++) {
                data[i][j] = new double[d3[j]];
                d3[j] = d3[j];
                for (int k = 0; k < d3[j]; k++) {
                    data[i][j][k] = 0.0;
                }
            }
        }
    }

    ThreeDArray(const ThreeDArray& other) : d1(other.d1), d2(other.d2), d3(new int[d2]), data(new double** [d1]) {   //Konstruktor kopiujący
        for (int i = 0; i < d1; i++) {
            data[i] = new double* [d2];
            for (int j = 0; j < d2; j++) {
                data[i][j] = new double[other.d3[j]];
                d3[j] = other.d3[j];
                for (int k = 0; k < other.d3[j]; k++) {
                    data[i][j][k] = other.data[i][j][k];
                }
            }
        }
    }

    ThreeDArray& operator=(const ThreeDArray& other) {                                                         //Operator przypisania
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < d1; i++) {
            for (int j = 0; j < d2; j++) {
                delete[] data[i][j];
            }
            delete[] data[i];
        }
        delete[] data;
        delete[] d3;

        d1 = other.d1;
        d2 = other.d2;
        d3 = new int[d2];
        data = new double** [d1];
        for (int i = 0; i < d1; i++) {
            data[i] = new double* [d2];
            for (int j = 0; j < d2; j++) {
                data[i][j] = new double[other.d3[j]];
                d3[j] = other.d3[j];
                for (int k = 0; k < other.d3[j]; k++) {
                    data[i][j][k] = other.data[i][j][k];
                }
            }
        }

        return *this;
    }

    ~ThreeDArray() {                                                                                      //Destruktor   
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            delete[] data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
    delete[] d3;
}

void Print() const {
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            cout << "[ ";
            for (int k = 0; k < d3[j]; k++) {
                cout << data[i][j][k] << " ";
            }
            cout << "]";
        }
        cout << endl;
    }
}

void Insert(int i, int j, int k, double value) {
    if (i < 0 || i >= d1 || j < 0 || j >= d2 || k < 0 || k >= d3[j]) {
        cout << "Blad" << endl;
        return;
    }
    data[i][j][k] = value;
}
};

int main() {
    int d1 = 2, d2 = 3;
    int d3[] = { 2, 3, 4 };
    ThreeDArray arr(d1, d2, d3);

    arr.Print();  // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 0 ]
                  // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 0 ]

    arr.Insert(0, 1, 2, 1.5);
    arr.Insert(1, 2, 3, 2.0);

    arr.Print();  // [ 0 0 ] [ 0 0 1.5 ] [ 0 0 0 0 ]
                  // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 2 ]
    
    ThreeDArray arr2 = arr;

    arr2.Print();  // [ 0 0 ] [ 0 0 1.5 ] [ 0 0 0 0 ]
                   // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 2 ]

    arr2.Insert(0, 0, 0, 3.5);

    arr2.Print();  // [ 3.5 0 ] [ 0 0 1.5 ] [ 0 0 0 0 ]
                  // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 2 ]

    arr.Print();   // [ 0 0 ] [ 0 0 1.5 ] [ 0 0 0 0 ]
                  // [ 0 0 ] [ 0 0 0 ] [ 0 0 0 2 ]

    return 0;
}

