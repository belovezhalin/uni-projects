#include <iostream>
using namespace std;

class TwoDArray {
private:
    int rows;
    int *columns;
    double *data;
    int size = 0;

public:
    TwoDArray() : rows(0), columns(NULL), data(NULL) {}                                       //konstruktor domyślny
    
    TwoDArray(int rowsnumber, int *columnsnumber) : rows(rowsnumber), columns(new int[rowsnumber]), data(NULL) {  //konstruktor tworzący tablicę o podanych pojemnościach wypełnioną zerami
        for (int i = 0; i < rowsnumber; i++) {
            columns[i] = columnsnumber[i];
            size += columnsnumber[i];
        }
        if (size > 0) {
            data = new double[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0.0;
            }
        }
    }
    
    TwoDArray(const TwoDArray& other) : rows(other.rows), columns(new int[other.rows]), data(NULL) {   //konstruktor kopiujący
        for (int i = 0; i < other.rows; i++) {
            columns[i] = other.columns[i];
        }
        size = other.size;
        if (size > 0) {
            data = new double[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }
     
    ~TwoDArray() {                                                                                    //destruktor
        delete[] columns;
        delete[] data;
    }
    
    void Print() {
        cout << "[";
        int index = 0;
        for (int i = 0; i < rows; i++) {
            cout << "[";
            for (int j = 0; j < columns[i]; j++) {
                cout << data[index++] << ", ";
            }
            cout << "], ";
        }
        cout << "]" << endl;
    }
    
    void Insert(double value, int row, int col) {
        int index = 0;
        for (int i = 0; i < row; i++) {
            index += columns[i];
        }
        index += col;
        data[index] = value;
    }
    
    TwoDArray& operator=(const TwoDArray& other) {                                                    //Operator przypisania
        if (this != &other) {
            delete[] columns;
            delete[] data;
            rows = other.rows;
            columns = new int[rows];
            for (int i = 0; i < rows; i++) {
                columns[i] = other.columns[i];
            }
            size = other.size;
            if (size > 0) {
                data = new double[size];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            }
        }
        return *this;
    }
};

int main() {
    int rowsnumber = 3;
    int columnsnumber[] = {2, 3, 1};
    TwoDArray array(rowsnumber, columnsnumber);
    array.Print(); // [[0, 0], [0, 0, 0], [0]]
    array.Insert(2.5, 1, 1);
    array.Print(); // [[0, 0], [0, 2.5, 0], [0]]
    TwoDArray array2(array);
    array2.Print(); // [[0, 0], [0, 2.5, 0], [0]] 
    TwoDArray array3;
    array3 = array2;
    array3.Print(); // [[0, 0], [0, 2.5, 0], [0]]
return 0;
}
