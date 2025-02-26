#include <stdio.h>
#include <iostream>
using namespace std;


int main() {

	//PRINTF

	printf("Witaj!\n");

	int i = 3;
	float f = 5.3;
	char* n = "Filemona";

	printf("Ala %d ma %f kota %s \n", i, f, n); //printf wykorzystuje mechanizm dowolnej liczby argumentów

	//SCANF

	char imie[15];
	printf("Podaj swoje imie: ");
	scanf("%s", imie);
	printf("Milo Cie poznac, %s \n", imie);


	int calkowita;
	printf("Podaj liczbe calkowita: ");
	// scanf("%d", calkowita); // ¿le
	scanf("%d", &calkowita);
	printf("%d \n", calkowita);


	char napis[10];
	scanf("%s", napis);
	printf("%s \n", napis);

	//Wiêc czemu to nie dzia³a:

	char literka = 'a';
	scanf(" %c", &literka);
	printf("X%cX\n", literka);



	//scanf("%c", &literka);
	//scanf(" %c", &literka);


	cin.get();
	cin.ignore();
	return 0;

}

