#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

	cout << argv[0] << endl;

	for (int i = 0; i < argc; i++){
	cout << argv[i] << endl;
	 }

	char *tablicaCharow = new char[5];
	tablicaCharow[0] = 'a';
	tablicaCharow[1] = 'b';
	tablicaCharow[2] = '\0';
	tablicaCharow[3] = 'd';
	tablicaCharow[4] = 'e';
	string wyraz = tablicaCharow;

	for (int i = 0; i < 70; i++)
		cout << tablicaCharow[i] << endl;

	// cout << wyraz << endl;
	cout << wyraz.length() << endl;

	delete[] tablicaCharow;

	cin.ignore();
	return 0;
}
