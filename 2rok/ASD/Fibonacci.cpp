//Anhelina Belavezha
#include <iostream>
using namespace std;
 
void Fibonacci(int n) {                         //algorytm polega na zapamietywaniu poprzednich dwoch elementow, dlatego nie wykonuje sie
    int tab[10000];                             //zadne wywolanie rekurencyjne 
    int a = 0;
    int b = 1;
    int i = 0;
    while(a < n) {
        tab[i] = a;
        int temp = b;
        b = a + b;
        a = temp;
        i++;
    }
    for(int j = 0; j < i; j++) {
        cout << tab[j] << " ";
    }
}

int main() {
    int n = 1000;
    Fibonacci(n);
    return 0;
}
