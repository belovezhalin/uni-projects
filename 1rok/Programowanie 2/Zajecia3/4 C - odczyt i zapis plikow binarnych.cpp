#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	FILE* plikDoOdczytu = fopen("WejscieBinarne.txt", "rb");
	
	unsigned char bytes[5];

	fread(bytes, 1, 5, plikDoOdczytu); //1 = sizeof(unsigned char)
	for (int i = 0; i < 5; i++) {
		printf("%c", bytes[i]);
	}
	printf("\n");

	fclose(plikDoOdczytu);
	

	FILE* plikDoZapisu = fopen("WyjscieBinarne.txt", "wb");

	fwrite(bytes, 1, 5, plikDoZapisu); //1 = sizeof(unsigned char)

	fclose(plikDoZapisu);


	printf("Gotowe");
	return 0;

}
