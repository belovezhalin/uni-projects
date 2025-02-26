#include <stdio.h>
#include <iostream>
using namespace std;


int main() {

	FILE* wskaznikNaPlik = fopen("Wyjscie.txt", "w");

	if (wskaznikNaPlik == NULL)
	{
		printf("Blad!");
		cin.get();
		cin.ignore();
		return 1;
	}

	int i = 1234;
	fprintf(wskaznikNaPlik, "%d", i);

	fputs("ALA", wskaznikNaPlik);

	fclose(wskaznikNaPlik);

	printf("Gotowe");
	
	return 0;

}
