

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRT(unsigned short* rows, unsigned short** columns, int*** tab) {
	int i = 0, j = 0;

	if (*rows == 0) {
		printf("%d\n", *rows);
		return;}

	printf("%d\n", *rows);
	for (i = 0; i < *rows; i++) {
		printf("%d ", *(*columns + i));
		for (j = 0; j < *(*columns + i); j++) printf("%d ", *(*(*tab + i) + j));
		printf("\n");
		j = 0;}}

void AFR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int numberofnewelements = 0;		
	scanf("%hu", &numberofnewelements);

	int* newrow = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0, j = 0, temp = 0;	
	for (i = 0; i < numberofnewelements; i++) {		
		scanf("%d", &temp);
		*(newrow + i) = temp;}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	
	*newtab = newrow;										

	for (i = 1; i < *rows + 1; i++, j++) *(newtab + i) = *(*tab + j);					
	
	free(*tab);
	*tab = newtab;
	
	unsigned short int* newrowelements;
	newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));
	*newrowelements = numberofnewelements;

	j = 0;
	for (i = 1; i < *rows + 1; i++, j++) *(newrowelements + i) = *(*columns + j);

	free(*columns);
	*columns = newrowelements;
	*rows = *rows + 1;}

void ALR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int numberofnewelements = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &numberofnewelements);

	int* newrow = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	// nowa tablica 2D

	i = 0;
	for (i; i < *rows; ++i)
		*(newtab + i) = *(*tab + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
	*(newtab + i) = newrow;

	free(*tab);//nowe
	*tab = newtab;

	unsigned short int* newrowelements;
	newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < *rows; ++i)
		*(newrowelements + i) = *(*columns + i);
	*(newrowelements + i) = numberofnewelements;

	free(*columns);//nowe
	*columns = newrowelements;
	*rows = *rows + 1;
}

void AFC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int numberofnewelements = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &numberofnewelements);					

	if (numberofnewelements <= 0)
		return;

	int* newCol = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < numberofnewelements && i < *rows; ++i) {
		int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
		*newrow = *(newCol + i);
		j = 1;
		k = 0;
		for (j; j < (*(*columns + i) + 1); ++j, k++) 
			*(newrow + j) = *(*(*tab + i) + k);
		
		*(*columns + i) = *(*columns + i) + 1;
		free(*(*tab + i));//nowe
		*(*tab + i) = newrow;
	}
	while (i < numberofnewelements) {
		int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(newCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newtab + j) = *(*tab + j);					
		*(newtab + j) = newrow;
		
		free(*tab);//nowe
		*tab = newtab;

		unsigned short int* newrowelements;
		newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newrowelements + j) = *(*columns + j);
		*(newrowelements + j) = 1;
		free(*columns);//nowe
		*columns = newrowelements;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void ALC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int numberofnewelements = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &numberofnewelements);

	if (numberofnewelements <= 0)
		return;

	int* newCol = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < numberofnewelements && i < *rows; ++i) {
		int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
		j = 0;
		for (j; j < *(*columns + i); ++j)
			*(newrow + j) = *(*(*tab + i) + j);
		*(newrow + j) = *(newCol + i);

		*(*columns + i) = *(*columns + i) + 1;
		free(*(*tab + i));//nowe
		*(*tab + i) = newrow;
	}
	while (i < numberofnewelements) {
		int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(newCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newtab + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newtab + j) = newrow;

		free(*tab);//nowe
		*tab = newtab;

		unsigned short int* newrowelements;
		newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newrowelements + j) = *(*columns + j);
		*(newrowelements + j) = 1;
		free(*columns);//nowe
		*columns = newrowelements;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void IBR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	unsigned short int numberofnewelements = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &numberofnewelements);

	int* newrow = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	if (rowIndex < 0 || rowIndex >(*rows - 1)) {
		free(newrow); //nowe
		return;
	}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	
	unsigned short int* newrowelements;						
	newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < rowIndex; ++i) {
		*(newtab + i) = *(*tab + i);					
		*(newrowelements + i) = *(*columns + i);	
	}

	*(newtab + i) = newrow;
	*(newrowelements + i) = numberofnewelements;
	int j = i;
	i++;

	for (i; i < *rows + 1; ++i, ++j) {
		*(newtab + i) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newrowelements + i) = *(*columns + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*columns);//nowe
	*columns = newrowelements;
	free(*tab); //nowe
	*tab = newtab;
	*rows = *rows + 1;
}
//c
void IAR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	unsigned short int numberofnewelements = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &numberofnewelements);

	int* newrow = (int*)malloc(numberofnewelements * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	if (rowIndex < 0 || rowIndex >(*rows - 1)) {
		free(newrow);//nowe
		return;
	}

	int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));	// nowa tablica 2D
	unsigned short int* newrowelements;							// nowa tablica dlugosci wierszy
	newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < rowIndex + 1; ++i) {
		*(newtab + i) = *(*tab + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newrowelements + i) = *(*columns + i);	// zapisuje wszystke dlguosci wierwszy do nowej
	}

	*(newtab + i) = newrow;
	*(newrowelements + i) = numberofnewelements;
	int j = i;
	i++;

	for (i; i < *rows + 1; ++i, ++j) {
		*(newtab + i) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newrowelements + i) = *(*columns + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*columns);//nowe
	*columns = newrowelements;
	free(*tab);//nowe
	*tab = newtab;
	*rows = *rows + 1;
}
//c
void IBC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);
	if (colIndex < 0)
		return;

	unsigned short int numberofnewelements = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &numberofnewelements);

	int* elemsCol = (int*)malloc(numberofnewelements * sizeof(int));	// nowa kolumna

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &temp);
		*(elemsCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < numberofnewelements && i < *rows; ++i) {
		if (colIndex >= *(*columns + i)) {			// jesli sie nie miesci to na koniec
			int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < *(*columns + i); ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);

			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
		else {
			int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < colIndex; ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);
			k = j;
			j++;
			for (j; j < (*(*columns + i) + 1); ++j, ++k)
				*(newrow + j) = *(*(*tab + i) + k);
			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
	}
	while (i < numberofnewelements) {
		int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(elemsCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newtab + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newtab + j) = newrow;
		free(*tab);//nowe
		*tab = newtab;

		unsigned short int* newrowelements;
		newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newrowelements + j) = *(*columns + j);
		*(newrowelements + j) = 1;
		free(*columns);//nowe
		*columns = newrowelements;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(elemsCol);//nowe
}
//c
void IAC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);
	if (colIndex < 0)
		return;

	unsigned short int numberofnewelements = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &numberofnewelements);

	int* elemsCol = (int*)malloc(numberofnewelements * sizeof(int));	// nowa kolumna

	int i = 0;
	int temp = 0;
	for (i; i < numberofnewelements; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &temp);
		*(elemsCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < numberofnewelements && i < *rows; ++i) {
		if (colIndex >= *(*columns + i)) {			// jesli sie nie miesci to na koniec
			int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < *(*columns + i); ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);

			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
		else {
			int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
			j = 0;
			for (j; j <= colIndex; ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);
			k = j;
			j++;
			for (j; j < (*(*columns + i) + 1); ++j, ++k)
				*(newrow + j) = *(*(*tab + i) + k);
			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
	}
	while (i < numberofnewelements) {
		int** newtab = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(elemsCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newtab + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newtab + j) = newrow;

		free(*tab);//nowe
		*tab = newtab;

		unsigned short int* newrowelements;
		newrowelements = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newrowelements + j) = *(*columns + j);
		*(newrowelements + j) = 1;

		free(*columns);//nowe
		*columns = newrowelements;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(elemsCol);//nowe
}
//c
void SWR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int fsRowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &fsRowIndex);

	unsigned short int scRowIndex = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &scRowIndex);

	if (fsRowIndex < 0 || fsRowIndex >(*rows - 1) || scRowIndex < 0 || scRowIndex >(*rows - 1))
		return;

	int* fsRow = *(*tab + fsRowIndex);
	*(*tab + fsRowIndex) = *(*tab + scRowIndex);
	*(*tab + scRowIndex) = fsRow;

	unsigned short* fsRowNumber = *(*columns + fsRowIndex);
	*(*columns + fsRowIndex) = *(*columns + scRowIndex);
	*(*columns + scRowIndex) = fsRowNumber;
}
//c
void SWC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int fsColIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &fsColIndex);

	unsigned short int scColIndex = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &scColIndex);

	if (fsColIndex < 0 || scColIndex < 0)
		return;

	int i = 0;
	for (i; i < *rows; ++i) {
		if (fsColIndex > (*(*columns + i) - 1) || scColIndex >(*(*columns + i) - 1))
			continue;
		int fsCol = *(*(*tab + i) + fsColIndex);
		*(*(*tab + i) + fsColIndex) = *(*(*tab + i) + scColIndex);
		*(*(*tab + i) + scColIndex) = fsCol;
	}
}
//c
void DFR(unsigned short* rows, unsigned short** columns, int*** tab) {
	if (*rows == 0)
		return;
	
	int i = 0;
	unsigned short firstRowNum = **columns;
	int* firstRow = **tab;
	
	for (i; i < (*rows - 1); ++i) {		
		*(*tab + i) = *(*tab + i + 1);
		*(*columns + i) = *(*columns + i + 1);
	}
	*(*tab + i) = firstRow;
	*(*columns + i) = firstRowNum;
	free(firstRow);
	*tab = (int*)realloc(*tab, (*rows - 1) * sizeof(int*));
	*columns = (unsigned short int*)realloc(*columns, (*rows - 1) * sizeof(unsigned short int));
	*rows = *rows - 1;
}
//c
void DLR(unsigned short* rows, unsigned short** columns, int*** tab) {
	if (*rows == 0)
		return;

	free(*(*tab + *rows - 1));
	*tab = (int*)realloc(*tab, (*rows - 1) * sizeof(int*));
	*columns = (unsigned short int*)realloc(*columns, (*rows - 1) * sizeof(unsigned short int));
	*rows = *rows - 1;
}
//c
void Clear(unsigned short* rows, unsigned short** columns, int*** tab) {
	while (*rows != 0)
		DLR(rows, columns, tab);
}
//c
void DFC(unsigned short* rows, unsigned short** columns, int*** tab) {
	if (*rows == 0)
		return;

	int i = 0;
	int j = 0;
	unsigned short RowNum = 0;
	int* Row = NULL;
	int tmpInt = 0;

	for (i; i < *rows; ++i) {
		if (*(*columns + i) == 1) { // usuwanie wiersza
			RowNum = *(*columns + i);
			Row = *(*tab + i);
			j = i;
			for (j; j < *rows - 1; ++j) {
				*(*tab + j) = *(*tab + j + 1);
				*(*columns + j) = *(*columns + j + 1);
			}
			*(*tab + j) = Row;
			*(*columns + j) = RowNum;
			DLR(rows, columns, tab);
			i = i - 1;
		}
		else {
			tmpInt = **(*tab + i);
			j = 0;
			for (j; j < (*(*columns + i) - 1) ; ++j)
				*(*(*tab + i) + j) = *(*(*tab + i) + j + 1);
			
			*(*(*tab + i) + j) = tmpInt;
			*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) - 1 ) * sizeof(int*));
			*(*columns + i) = *(*columns + i) - 1;
		}
	}
}
//c
void DLC(unsigned short* rows, unsigned short** columns, int*** tab) {
	if (*rows == 0)
		return;

	int i = 0;
	int j = 0;
	unsigned short RowNum = 0;
	int* Row = NULL;

	for (i; i < *rows; ++i) {
		if (*(*columns + i) == 1) { // usuwanie wiersza
			RowNum = *(*columns + i);
			Row = *(*tab + i);
			j = i;
			for (j; j < *rows - 1; ++j) {
				*(*tab + j) = *(*tab + j + 1);
				*(*columns + j) = *(*columns + j + 1);
			}
			*(*tab + j) = Row;
			*(*columns + j) = RowNum;
			DLR(rows, columns, tab);
			i = i - 1;
		}
		else {
			*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) - 1) * sizeof(int*));
			*(*columns + i) = *(*columns + i) - 1;
		}
	}
}
//c
void RMR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	if (rowIndex < 0 || rowIndex >(*rows - 1))
		return;

	unsigned short RowNum = *(*columns + rowIndex);
	int* Row = *(*tab + rowIndex);

	int i = rowIndex;
	for (i; i < *rows - 1; ++i) {
		*(*tab + i) = *(*tab + i + 1);
		*(*columns + i) = *(*columns + i + 1);
	}
	*(*tab + i) = Row;
	*(*columns + i) = RowNum;

	DLR(rows, columns, tab);
}
//c
void RMC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int colIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &colIndex);
	
	if (colIndex < 0)
		return;

	int i = 0;
	int j = 0;
	int tmpInt = 0;
	for (i; i < *rows; ++i) {
		if (colIndex >= *(*columns + i))
			continue;
		else {
			if (*(*columns + i) - 1 == 0) {
				unsigned short RowNum = *(*columns + i);
				int* Row = *(*tab + i);
				j = i;
				for (j; j < *rows - 1; ++j) {
					*(*tab + j) = *(*tab + j + 1);
					*(*columns + j) = *(*columns + j + 1);
				}
				*(*tab + j) = Row;
				*(*columns + j) = RowNum;
				DLR(rows, columns, tab);
				i = i - 1;
			}
			else {
				j = colIndex;
				tmpInt = *(*(*tab + i) + colIndex);
				for (j; j < *(*columns + i) - 1; ++j) 
					*(*(*tab + i) + j) = *(*(*tab + i) + j + 1);
				
				*(*(*tab + i) + j) = tmpInt;
				*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) - 1) * sizeof(int*));
				*(*columns + i) = *(*columns + i) - 1;
			}
		}
	}

}
//c
void RMB(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int rowIndex = 0;			
	scanf("%hu", &rowIndex);
	
	unsigned short int rowCount = 0;			
	scanf("%hu", &rowCount);

	unsigned short int colIndex = 0;			
	scanf("%hu", &colIndex);

	unsigned short int colNumber = 0;			
	scanf("%hu", &colNumber);

	if (rowIndex >= *rows)
		return;

	int i = rowIndex;
	int j = 0;
	int k = 0;
	int l = 0;
	int tmp = 0;
	for (i; i < *rows && k < rowCount; ++i, ++k) {
		if (colIndex >= *(*columns + i))
			continue;
		else if (colIndex == 0 && *(*columns + i) <= colNumber) { 
			unsigned short RowNum = *(*columns + i);
			int* Row = *(*tab + i);
			j = i;
			for (j; j < *rows - 1; ++j) {
				*(*tab + j) = *(*tab + j + 1);
				*(*columns + j) = *(*columns + j + 1);
			}
			*(*tab + j) = Row;
			*(*columns + j) = RowNum;
			DLR(rows, columns, tab);
			i = i - 1;
		}
		else {
			j = colIndex;
			for (j; j + colNumber < *(*columns + i); ++j) 
				*(*(*tab + i) + j) = *(*(*tab + i) + j + colNumber);
			j = colIndex;
			l= 0;
			for (j; j < *(*columns + i) && l < colNumber; ++l, ++j);

			*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) - l) * sizeof(int*));
			*(*columns + i) = *(*columns + i) - l;
		}
	}



}
//c
void ISB(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int rowIndex = 0;
	scanf("%hu", &rowIndex);

	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);

	unsigned short int rowNumber = 0;
	scanf("%hu", &rowNumber);

	unsigned short int colNumber = 0;
	scanf("%hu", &colNumber);

	if (*rows - 1 < rowIndex) {
		int i = 0;
		for (i; i < rowNumber; ++i) {

			int* newrow = (int*)malloc(colNumber * sizeof(int));

			int j = 0;
			int temp = 0;
			for (j; j < colNumber; ++j) {		// zapisuje elementy do wiersza
				scanf("%d", &temp);
				*(newrow + j) = temp;
			}

			*tab = (int*)realloc(*tab, (*rows + 1) * sizeof(int*));	// nowa tablica 2D
			*(*tab + *rows) = newrow;									// zapisuje pierwszy nowy elemnt


			*columns = (unsigned short int*)realloc(*columns, (*rows + 1) * sizeof(unsigned short int));
			*(*columns + *rows) = colNumber;

			*rows = *rows + 1;
		}
	}
	else {
		int i = rowIndex;
		int j = 0;
		int temp;
		for (i; i < *rows && j< rowNumber; ++i, ++j) {
			if (colIndex >= *(*columns + i)) {	// jesli index sie nie miejsci
				*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) + colNumber) * sizeof(int));
				unsigned short int k = *(*columns + i);
				for (k; k < *(*columns + i) + colNumber; ++k) {
					scanf("%d", &temp);
					*(*(*tab + i) + k) = temp;
				}
				*(*columns + i) = *(*columns + i) + colNumber;
			}
			else {
				int* newrow = (int*)malloc((*(*columns + i) + colNumber) * sizeof(int));
				unsigned short int k = 0;
				for (k; k < colIndex; ++k) 
					*(newrow + k) = *(*(*tab + i) + k);
				unsigned short int l = 0;
				unsigned short int s = k;
				for (l; l < colNumber; ++l, ++k) {
					scanf("%d", &temp);
					*(newrow + k) = temp;
				}
				for (s; s < *(*columns + i); ++k, ++s)
					*(newrow + k) = *(*(*tab + i) + s);
				
				free(*(*tab + i));
				*(*tab + i) = newrow;
				*(*columns + i) = *(*columns + i) + colNumber;
			}
		}
		for (j; j < rowNumber; ++j) {
			int* newrow = (int*)malloc(colNumber * sizeof(int));

			int j = 0;
			int temp = 0;
			for (j; j < colNumber; ++j) {		// zapisuje elementy do wiersza
				scanf("%d", &temp);
				*(newrow + j) = temp;
			}

			*tab = (int*)realloc(*tab, (*rows + 1) * sizeof(int*));	// nowa tablica 2D
			*(*tab + *rows) = newrow;									// zapisuje pierwszy nowy elemnt


			*columns = (unsigned short int*)realloc(*columns, (*rows + 1) * sizeof(unsigned short int));
			*(*columns + *rows) = colNumber;

			*rows = *rows + 1;
		}
	}

}

void WRF(unsigned short* rows, unsigned short** columns, int*** tab) {
	char* fname = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", fname);

	if (fname == "")
		return;

	FILE* fileVar = fopen(fname, "wb");

	fprintf(fileVar, "%d\n", *rows);
	if (*rows > 0) {
		int i = 0;
		for (i; i < *rows; ++i) {
			int x = ((*(*columns + i) >> 8) & 255);
			fputc(((*(*columns + i) >> 8) & 255), fileVar);
			fputc(((*(*columns + i) >> 0) & 255), fileVar);
			int j = 0;
			for (j; j < *(*columns + i); ++j) {
				fputc(((*(*(*tab +i ) + j) >> 24) & 255), fileVar);
				fputc(((*(*(*tab +i ) + j) >> 16) & 255), fileVar);
				fputc(((*(*(*tab +i ) + j) >> 8) & 255), fileVar);
				fputc(((*(*(*tab +i ) + j) >> 0) & 255), fileVar);
			}
		}
	}
	fclose(fileVar);
	free(fname);
}

void RDF(unsigned short* rows, unsigned short** columns, int*** tab) {
	Clear(rows, columns, tab);

	*tab = NULL;
	*rows = 0;
	*columns = NULL;

	char* fname = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", fname);
	unsigned char ch = ' ';
	unsigned short rN = 0;
	FILE* fileVar = fopen(fname, "rb");
	while (1) {
		fread(&ch, sizeof(char), 1, fileVar);
		if (ch == '\n')
			break;
		rN *= 10;
		rN += ch - '0';
	}
	*rows = rN;
	*tab = (int**)malloc((*rows) * sizeof(int*));
	*columns = (unsigned short int*)malloc(*rows * sizeof(unsigned short int));
	int i = 0;
	for (i = 0; i < *rows; ++i) {
		unsigned short int lk;
		lk = (fgetc(fileVar) << 8) + (fgetc(fileVar) << 0);
		*(*columns + i) = lk;
		*(*tab + i) = (int*)malloc(lk * sizeof(int));
		int j = 0;
		for (j; j < lk; ++j) {
			int elem = 0;
			elem = (fgetc(fileVar) << 24) + (fgetc(fileVar) << 16) + (fgetc(fileVar) << 8) + (fgetc(fileVar) << 0);
			*(*(*tab + i) + j) = elem;
		}
	}
	fclose(fileVar);
	free(fname);
}


int main() {
	unsigned short  rows = 0;						
	unsigned short *columns = NULL;			
	int** tab = NULL;								

	char* operation = (char*)malloc(sizeof(char) * 100);

	while (!0) {
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