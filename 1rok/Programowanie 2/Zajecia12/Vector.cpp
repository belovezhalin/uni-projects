#include <iostream>
#include <vector>
using namespace std;

void UseVector() {
    vector<int> vec = {4, 5, 6, 12, 88, -3, 5, 21};

    cout << "Elementy wektora:" << endl;
    for (const auto& element : vec) {                                       //dedukcja typu dla elementow wektora
        cout << element << " ";
    }
    cout << endl;
}
