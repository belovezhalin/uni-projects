#include <iostream>
using namespace std; 

int main() {
	int x,y; 
	int n=10;
	int tab[n][n];
	int suma;
	
	for (x=0;x<n;x++)
	{
	cout << endl;
	for (y=0;y<n;y++)
	{ 
	if (x==y) tab[x][y] = 1; 
	else tab[x][y] = 0; 
	if (x==y) suma = suma + 1;
	cout << tab[x][y] << " ";
	}
}
cout << "suma wynosi: " <<suma; 
	return 0;
}
