#include <iostream>
#include <array>
using namespace std;

void UseArray() {
    array<int, 11> arr = {1, 2, 3, 8, 12, 3, 9, 75, 12, -9, 13};

    cout << "Elementy tablicy:" << endl;
    for (const auto& element : arr) {                                       //dedukcja typu dla elementow tablicy
        cout << element << " ";
    }
    cout << endl;
}
