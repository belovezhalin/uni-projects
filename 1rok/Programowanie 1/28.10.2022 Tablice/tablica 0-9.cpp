#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int const n = 10;
	int i, dane[n];
	
	for (i = 0; i < 10; i++) {
		dane[i] = i;
        cout << "dane[" << i <<"] = " << dane[i] << endl;}
        
        cout << endl << endl;
        
    for (i = 0; i < 10; i++) {
    	dane[i] = n-1-i;
    	cout << "dane["<< i <<"] = " << dane[i] << endl;}
	    
return 0;
}
