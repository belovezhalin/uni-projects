#include <iostream>
using namespace std;

int function1 (int *a, int *b) {
	if (*a > *b) return *b;
	else if (*a < *b) return *a;
}

int main () {
	int liczba1 = 4;
	int liczba2 = 7;
	
	cout << function1 (liczba1, liczba2);
}

int function2 (int *a, int *b) {
	if (*a > *b) return b;
	else if (*a < *b) return a;
}

int function3 (int *a, int *b) {
    int bufor;
	bufor = *a;
	*a = *b;
    *b = bufor;
}

int function4 (int &a, int &b) {
    int bufor;
	bufor = a;
	a = b;
    b = bufor;
}

int *function5 () {
	return new int;
}

int *function6 (int n) {
	return new int [n];
}

void function7 (int const *a, int *b) {
	*b = *a;
}


