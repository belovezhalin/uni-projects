//Anhelina Belavezha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRT(unsigned short* rows, unsigned short** columns, int*** tab) {
	/*
	if(*rows == 0) {
		printf("%d\n", *rows);
		return;}
	printf("%d\n", *rows);

	int i = 0, j = 0;
	for(i = 0; i < *rows; i++) {
		printf("%d ", *(*columns + i));
		for (j = 0; j < *(*columns + i); j++) {printf("%d ", *(*(*tab + i) + j));}
		printf("\n");
		j = 0;}
		*/}
/*
void RDF(unsigned short* rows, unsigned short** columns, int*** tab) {
	Clear(rows, columns, tab);

	*tab = NULL;
	*rows = 0;
	*columns = NULL;

	char* filename = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", filename);

	unsigned char symbol = ' ';
	unsigned short numberofrows = 0;

	FILE* file = fopen(filename, "rb");

	while (100) {
		fread(&symbol, sizeof(char), 1, file);
		if (symbol == '\n') break;
		numberofrows *= 10;
		numberofrows += symbol - '0';}
	
	*rows = numberofrows;
	*tab = (int**)malloc((*rows) * sizeof(int*));
	*columns = (unsigned short int*)malloc(*rows * sizeof(unsigned short int));

	int i = 0;
	for (i = 0; i < *rows; i++) {
		unsigned short int numberofcolumns;
		numberofcolumns = (fgetc(file) << 8) + (fgetc(file) << 0);

		*(*columns + i) = numberofcolumns;
		*(*tab + i) = (int*)malloc(numberofcolumns * sizeof(int));

		int j = 0;
		for (j = 0; j < numberofcolumns; j++) {
			int element = 0;
			element = (fgetc(file) << 24) + (fgetc(file) << 16) + (fgetc(file) << 8) + (fgetc(file) << 0);
			*(*(*tab + i) + j) = element;}}
	fclose(file);
	free(filename);}

/*
void WRF(unsigned short* rows, unsigned short** columns, int*** tab) {
	char* filename = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", filename);

	if (filename == "") return;
	FILE* file = fopen(filename, "wb");

	fprintf(file, "%d\n", *rows);

	if (*rows != 0) {
		int i = 0;
		for (i = 0; i < *rows; i++) {
			int x = ((*(*columns + i) >> 8) & 255);
			fputc(((*(*columns + i) >> 8) & 255), file);
			fputc(((*(*columns + i) >> 0) & 255), file);

			int j = 0;
			for (j = 0; j < *(*columns + i); j++) {
				fputc(((*(*(*tab +i ) + j) >> 24) & 255), file);
				fputc(((*(*(*tab +i ) + j) >> 16) & 255), file);
				fputc(((*(*(*tab +i ) + j) >> 8) & 255), file);
				fputc(((*(*(*tab +i ) + j) >> 0) & 255), file);}}}
	fclose(file);
	free(filename);}

void WRF(unsigned short* rows, unsigned short** columns, int*** tab) {
	char* filename = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", filename);

	if (filename == "") return;
	FILE* file = fopen(filename, "wb");

	fprintf(file, "%d\n", *rows);

	if (*rows != 0) {
		int i = 0;
		for (i = 0; i < *rows; i++) {
			int x = ((*(*columns + i) >> 8) & 255);
			unsigned char buf[2];
			buf[0] = ((*(*columns + i) >> 8) & 255);
			buf[1] = ((*(*columns + i) >> 0) & 255);
			fwrite(buf, sizeof(buf), 1, file);

			int j = 0;
			for (j = 0; j < *(*columns + i); j++) {
				unsigned char buf[4];
				buf[0] = ((*(*(*tab + i) + j) >> 24) & 255);
				buf[1] = ((*(*(*tab + i) + j) >> 16) & 255);
				buf[2] = ((*(*(*tab + i) + j) >> 8) & 255);
				buf[3] = ((*(*(*tab + i) + j) >> 0) & 255);
				fwrite(buf, sizeof(buf), 1, file);}}}
	fclose(file);
	free(filename);}

void RDF(unsigned short* rows, unsigned short** columns, int*** tab) {
	Clear(rows, columns, tab);

	*tab = NULL;
	*rows = 0;
	*columns = NULL;

	char* filename = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", filename);

	unsigned char symbol = ' ';
	unsigned short numberofrows = 0;

	FILE* file = fopen(filename, "rb");

    int count = 0;
    while (symbol != '\n') {
        fread(&symbol, sizeof(char), 1, file);
        if (symbol == '\n') break;
        numberofrows *= 10;
        numberofrows += symbol - '0';
        count++;}
	
	*rows = numberofrows;
	*tab = (int**)malloc((*rows) * sizeof(int*));
	*columns = (unsigned short int*)malloc(*rows * sizeof(unsigned short int));

	int i = 0;
	for (i = 0; i < *rows; i++) {
		unsigned short int numberofcolumns = 0;
        int j = 0;
		for (j = 0; j < 2; j++) {
            fread(&symbol, sizeof(char), 1, file);
            numberofcolumns = (numberofcolumns << 8) + symbol;}
        
        *(*columns + i) = numberofcolumns;
        *(*tab + i) = (int*)malloc(numberofcolumns * sizeof(int));

        for (j = 0; j < numberofcolumns; j++) {
            int element = 0;
            int x = 0;
            for (x = 0; x < 4; x++) {
                fread(&symbol, sizeof(char), 1, file);
                element = (element << 8) + symbol;}
            *(*(*tab + i) + j) = element;}}
    fclose(file);
    free(filename);}
*/
void ISB(unsigned short* rows, unsigned short** columns, int*** tab) {}

void RMB(unsigned short* rows, unsigned short** columns, int*** tab) {}

void RMC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void RMR(unsigned short* rows, unsigned short** columns, int*** tab) {}

void DLC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void DFC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void DFR(unsigned short* rows, unsigned short** columns, int*** tab) {}

void SWC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void SWR(unsigned short* rows, unsigned short** columns, int*** tab) {}

void IAC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void IBC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void IAR(unsigned short* rows, unsigned short** columns, int*** tab) {}

void IBR(unsigned short* rows, unsigned short** columns, int*** tab) {}

void ALC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void AFC(unsigned short* rows, unsigned short** columns, int*** tab) {}

void ALR(unsigned short* rows, unsigned short** columns, int*** tab) {
	/*
	unsigned short int numberofelements = 0;			
	scanf("%hu", &numberofelements);

	int* newrow = (int*)malloc(numberofelements * sizeof(int));

	int i = 0, temp = 0;
	for(i = 0; i < numberofelements; i++) {		
		scanf("%d", &temp);
		*(newrow + i) = temp;}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	

	for(i = 0; i < *rows; ++i) {*(newtab + i) = *(*tab + i);}					
	*(newtab + i) = newrow;

	free(*tab);
	*tab = newtab;
	unsigned short int* newelements;
	newelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	for(i = 0; i < *rows; ++i) {*(newelements + i) = *(*columns + i);}
	*(newelements + i) = numberofelements;

	free(*columns);
	*columns = newelements;
	*rows = *rows + 1;
	*/}

void AFR(unsigned short* rows, unsigned short** columns, int*** tab) {
	/*
	unsigned short int numberofelements = 0;			
	scanf("%hu", &numberofelements);

	int* newrow = (int*)malloc(numberofelements * sizeof(int));

	int i = 0, temp = 0;	
	for(i = 0; i < numberofelements; i++) {		
		scanf("%d", &temp);
		*(newrow + i) = temp;}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	
	*newtab = newrow;										

	int j = 0;
	for(i = 1; i < *rows + 1; i++, j++) {*(newtab + i) = *(*tab + j);}					
	
	free(*tab);
	*tab = newtab;
	
	unsigned short int* newelements;
	newelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));
	*newelements = numberofelements;

	j = 0;
	for(i = 1; i < *rows + 1; i++, j++) {*(newelements + i) = *(*columns + j);}

	free(*columns);
	*columns = newelements;
	*rows = *rows + 1;
	*/}

void DLR(unsigned short* rows, unsigned short** columns, int*** tab) {
	/*
	if (*rows == 0) return;
	free(*(*tab + *rows - 1));
	*tab = (int*)realloc(*tab, (*rows - 1) * sizeof(int*));
	*columns = (unsigned short int*)realloc(*columns, (*rows - 1) * sizeof(unsigned short int));
	*rows = *rows - 1;
	*/}

void Clear(unsigned short* rows, unsigned short** columns, int*** tab) {
	while (*rows != 0) {DLR(rows, columns, tab);}}

int main() {
	unsigned short int rows = 0;						
	unsigned short int *columns = NULL;			
	int** tab = NULL;								
	char* operation = (char*)malloc(sizeof(char) * 100);

	while (100) {
		scanf("%3s", operation);

		if (strcmp(operation, "AFR") == 0) AFR(&rows, &columns, &tab);
		else if (strcmp(operation, "ALR") == 0) ALR(&rows, &columns, &tab);
		else if (strcmp(operation, "AFC") == 0) AFC(&rows, &columns, &tab);
		else if (strcmp(operation, "ALC") == 0) ALC(&rows, &columns, &tab);
		else if (strcmp(operation, "IBR") == 0) IBR(&rows, &columns, &tab);
		else if (strcmp(operation, "IAR") == 0) IAR(&rows, &columns, &tab);
		else if (strcmp(operation, "IBC") == 0) IBC(&rows, &columns, &tab);
		else if (strcmp(operation, "IAC") == 0) IAC(&rows, &columns, &tab);
		else if (strcmp(operation, "SWR") == 0) SWR(&rows, &columns, &tab);
		else if (strcmp(operation, "SWC") == 0) SWC(&rows, &columns, &tab);
		else if (strcmp(operation, "DFR") == 0) DFR(&rows, &columns, &tab);
		else if (strcmp(operation, "DLR") == 0) DLR(&rows, &columns, &tab);
		else if (strcmp(operation, "DFC") == 0) DFC(&rows, &columns, &tab);
		else if (strcmp(operation, "DLC") == 0) DLC(&rows, &columns, &tab);
		else if (strcmp(operation, "RMR") == 0) RMR(&rows, &columns, &tab);
		else if (strcmp(operation, "RMC") == 0) RMC(&rows, &columns, &tab);
		else if (strcmp(operation, "RMB") == 0) RMB(&rows, &columns, &tab);
		else if (strcmp(operation, "ISB") == 0) ISB(&rows, &columns, &tab);
		else if (strcmp(operation, "WRF") == 0) WRF(&rows, &columns, &tab);
		else if (strcmp(operation, "RDF") == 0) RDF(&rows, &columns, &tab);
        else if (strcmp(operation, "PRT") == 0) PRT(&rows, &columns, &tab);
		else if (strcmp(operation, "END") == 0) break;

		fflush(stdin);}

	Clear(&rows, &columns, &tab);
	free(operation);
	return 0;}