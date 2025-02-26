#include <iostream>
using namespace std;


typedef struct { int a; float b; } MojaStruktura;
typedef int MojaTablica [3];


int main() {

	MojaStruktura s = { 1, 2. };

	cout << s.a << " " << s.b << endl;

	MojaTablica t = { 3, 4, 5 };

	cout << t[0] << " " << t[1] << " " << t[2] << endl;

	cin.ignore();
	return 0;
}

