#include <iostream>
using namespace std;

int main() {
	int const n=10;
	int tab[n][n] = {};
	int tab0[10][10] = {};
	int trans[n][n] = {};
	int i,j;
	
	for (i=0;i<10;i++)
	{
	cout << endl;
	for (j=0;j<10;j++)
	{ tab[i][j] = j;
	cout <<tab[i][j];}}

    cout << endl;
    
    for (i=0;i<10;i++)
	{
	cout << endl;
	for (j=0;j<10;j++)
	{ tab0[i][j] = tab[j][i];
	cout << tab0[i][j];
	}}
	
	
	return 0;
}
