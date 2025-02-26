#include <stdio.h>
#include <iostream>
using namespace std;


int main() {

	FILE* wskaznikNaPlik = fopen("C:\\Users\\Michal\\OneDrive\\Work\\Zajêcia\\Programowanie lato 2018-2019\\Zajêcia 3\\Zajecia 3\\Wejscie.txt", "r");
	/*
	r  - open for reading
	w  - open for writing (file need not exist)
	a  - open for appending (file need not exist)
	r+ - open for reading and writing, start at beginning
	w+ - open for reading and writing (overwrite file)
	a+ - open for reading and writing (append if file exists)
	*/

	if (wskaznikNaPlik == NULL)
	{
		printf("Blad!");
		cin.get();
		cin.ignore();
		return 1;
	}

	char wyraz[100];
	while (fscanf(wskaznikNaPlik, "%s", wyraz) != EOF) {
		printf("%s\n", wyraz);
	}

/*	
	char linijka[100];
	while (!feof(wskaznikNaPlik)) {
		fgets(linijka, 100, wskaznikNaPlik);
		printf("%s", linijka);
	}
*/		

	fclose(wskaznikNaPlik);

	return 0;

}
