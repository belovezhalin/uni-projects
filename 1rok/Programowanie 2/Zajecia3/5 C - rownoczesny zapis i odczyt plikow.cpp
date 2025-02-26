#include <stdio.h>
#include <iostream>
using namespace std;


int main() {

	char napis[80];
	float liczba;
	FILE * wskaznikNaPlik;

	wskaznikNaPlik = fopen("Plik.txt", "w+");


	fprintf(wskaznikNaPlik, "%f %s", 3.1416, "PI");
	rewind(wskaznikNaPlik);
	fscanf(wskaznikNaPlik, "%f", &liczba);
	fscanf(wskaznikNaPlik, "%s", napis);
	fclose(wskaznikNaPlik);
	printf("Przeczytalem %f oraz %s \n", liczba, napis);

	return 0;

}
