//Anhelina Belavezha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PRT(unsigned short* rows, unsigned short** columns, int*** tab) {
	int i = 0;
	int j = 0;

	if (*rows == 0) {
		printf("%d\n", *rows);
		return;
	}

	printf("%d\n", *rows);
	for (i; i < *rows; ++i) {
		printf("%d ", *(*columns + i));
		for (j; j < *(*columns + i); ++j)
			printf("%d ", *(*(*tab + i) + j));
		printf("\n");
		j = 0;
	}
}
// c
void AFR(unsigned short* rows, unsigned short** columns, int*** tab) {
	
	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newrow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;	
	for (i; i < elemsNum; ++i) {		
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));	

	*newArray = newrow;										

	i = 1;
	int j = 0;
	for (i; i < *rows + 1; ++i, ++j)
		*(newArray + i) = *(*tab + j);					
	
	free(*tab);//nowe
	*tab = newArray;
	
	unsigned short int * newEachRowElems;
	newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int ));
	*newEachRowElems = elemsNum;

	i = 1;
	j = 0;
	for (i; i < *rows + 1; ++i, ++j) 
		*(newEachRowElems + i) = *(*columns + j);
	free(*columns);//nowe
	*columns = newEachRowElems;
	*rows = *rows + 1;
}
// c
void ALR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newrow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));	// nowa tablica 2D

	i = 0;
	for (i; i < *rows; ++i)
		*(newArray + i) = *(*tab + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
	*(newArray + i) = newrow;

	free(*tab);//nowe
	*tab = newArray;

	unsigned short int* newEachRowElems;
	newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < *rows; ++i)
		*(newEachRowElems + i) = *(*columns + i);
	*(newEachRowElems + i) = elemsNum;

	free(*columns);//nowe
	*columns = newEachRowElems;
	*rows = *rows + 1;
}
//c
void AFC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int elemsNum = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &elemsNum);					

	if (elemsNum <= 0)
		return;

	int* newCol = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int x = 0;
	for (i; i < elemsNum && i < *rows; ++i) {
		int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
		*newrow = *(newCol + i);
		j = 1;
		x = 0;
		for (j; j < (*(*columns + i) + 1); ++j, x++) 
			*(newrow + j) = *(*(*tab + i) + x);
		
		*(*columns + i) = *(*columns + i) + 1;
		free(*(*tab + i));//nowe
		*(*tab + i) = newrow;
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(newCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newArray + j) = *(*tab + j);					
		*(newArray + j) = newrow;
		
		free(*tab);//nowe
		*tab = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newEachRowElems + j) = *(*columns + j);
		*(newEachRowElems + j) = 1;
		free(*columns);//nowe
		*columns = newEachRowElems;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void ALC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int elemsNum = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &elemsNum);

	if (elemsNum <= 0)
		return;

	int* newCol = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int x = 0;
	for (i; i < elemsNum && i < *rows; ++i) {
		int* newrow = (int*)malloc((*(*columns + i) + 1) * sizeof(int));
		j = 0;
		for (j; j < *(*columns + i); ++j)
			*(newrow + j) = *(*(*tab + i) + j);
		*(newrow + j) = *(newCol + i);

		*(*columns + i) = *(*columns + i) + 1;
		free(*(*tab + i));//nowe
		*(*tab + i) = newrow;
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(newCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newArray + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newrow;

		free(*tab);//nowe
		*tab = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newEachRowElems + j) = *(*columns + j);
		*(newEachRowElems + j) = 1;
		free(*columns);//nowe
		*columns = newEachRowElems;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void IBR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int irow = 0;			// wczytanie numeru wiersza
	scanf("%hu", &irow);

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newrow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	if (irow < 0 || irow >(*rows - 1)) {
		free(newrow); //nowe
		return;
	}

	int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));	
	unsigned short int* newEachRowElems;						
	newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < irow; ++i) {
		*(newArray + i) = *(*tab + i);					
		*(newEachRowElems + i) = *(*columns + i);	
	}

	*(newArray + i) = newrow;
	*(newEachRowElems + i) = elemsNum;
	int j = i;
	i++;

	for (i; i < *rows + 1; ++i, ++j) {
		*(newArray + i) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*columns + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*columns);//nowe
	*columns = newEachRowElems;
	free(*tab); //nowe
	*tab = newArray;
	*rows = *rows + 1;
}
//c
void IAR(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int irow = 0;			// wczytanie numeru wiersza
	scanf("%hu", &irow);

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newrow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &temp);
		*(newrow + i) = temp;
	}

	if (irow < 0 || irow >(*rows - 1)) {
		free(newrow);//nowe
		return;
	}

	int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));	// nowa tablica 2D
	unsigned short int* newEachRowElems;							// nowa tablica dlugosci wierszy
	newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < irow + 1; ++i) {
		*(newArray + i) = *(*tab + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*columns + i);	// zapisuje wszystke dlguosci wierwszy do nowej
	}

	*(newArray + i) = newrow;
	*(newEachRowElems + i) = elemsNum;
	int j = i;
	i++;

	for (i; i < *rows + 1; ++i, ++j) {
		*(newArray + i) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*columns + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*columns);//nowe
	*columns = newEachRowElems;
	free(*tab);//nowe
	*tab = newArray;
	*rows = *rows + 1;
}
//c
void IBC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int icolumn = 0;
	scanf("%hu", &icolumn);
	if (icolumn < 0)
		return;

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* elemsCol = (int*)malloc(elemsNum * sizeof(int));	// nowa kolumna

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &temp);
		*(elemsCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int x = 0;
	for (i; i < elemsNum && i < *rows; ++i) {
		if (icolumn >= *(*columns + i)) {			// jesli sie nie miesci to na koniec
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
			for (j; j < icolumn; ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);
			x = j;
			j++;
			for (j; j < (*(*columns + i) + 1); ++j, ++x)
				*(newrow + j) = *(*(*tab + i) + x);
			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(elemsCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newArray + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newrow;
		free(*tab);//nowe
		*tab = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newEachRowElems + j) = *(*columns + j);
		*(newEachRowElems + j) = 1;
		free(*columns);//nowe
		*columns = newEachRowElems;
		*rows = *rows + 1;
		i = i + 1;
	}
	free(elemsCol);//nowe
}
//c
void IAC(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int icolumn = 0;
	scanf("%hu", &icolumn);
	if (icolumn < 0)
		return;

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* elemsCol = (int*)malloc(elemsNum * sizeof(int));	// nowa kolumna

	int i = 0;
	int temp = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &temp);
		*(elemsCol + i) = temp;
	}

	i = 0;
	int j = 0;
	int x = 0;
	for (i; i < elemsNum && i < *rows; ++i) {
		if (icolumn >= *(*columns + i)) {			// jesli sie nie miesci to na koniec
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
			for (j; j <= icolumn; ++j)
				*(newrow + j) = *(*(*tab + i) + j);
			*(newrow + j) = *(elemsCol + i);
			x = j;
			j++;
			for (j; j < (*(*columns + i) + 1); ++j, ++x)
				*(newrow + j) = *(*(*tab + i) + x);
			*(*columns + i) = *(*columns + i) + 1;
			free(*(*tab + i));//nowe
			*(*tab + i) = newrow;
		}
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rows + 1) * sizeof(int*));
		int* newrow = (int*)malloc(sizeof(int));
		*newrow = *(elemsCol + i);
		j = 0;
		for (j; j < *rows; ++j)
			*(newArray + j) = *(*tab + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newrow;

		free(*tab);//nowe
		*tab = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rows + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rows; ++j)
			*(newEachRowElems + j) = *(*columns + j);
		*(newEachRowElems + j) = 1;

		free(*columns);//nowe
		*columns = newEachRowElems;
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
	unsigned short int irow = 0;			// wczytanie numeru wiersza
	scanf("%hu", &irow);

	if (irow < 0 || irow >(*rows - 1))
		return;

	unsigned short RowNum = *(*columns + irow);
	int* Row = *(*tab + irow);

	int i = irow;
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
	unsigned short int icolumn = 0;			// wczytanie numeru wiersza
	scanf("%hu", &icolumn);
	
	if (icolumn < 0)
		return;

	int i = 0;
	int j = 0;
	int tmpInt = 0;
	for (i; i < *rows; ++i) {
		if (icolumn >= *(*columns + i))
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
				j = icolumn;
				tmpInt = *(*(*tab + i) + icolumn);
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
	unsigned short int irow = 0;			
	scanf("%hu", &irow);
	
	unsigned short int rowCount = 0;			
	scanf("%hu", &rowCount);

	unsigned short int icolumn = 0;			
	scanf("%hu", &icolumn);

	unsigned short int numberofcolumn = 0;			
	scanf("%hu", &numberofcolumn);

	if (irow >= *rows)
		return;

	int i = irow;
	int j = 0;
	int x = 0;
	int l = 0;
	int tmp = 0;
	for (i; i < *rows && x < rowCount; ++i, ++x) {
		if (icolumn >= *(*columns + i))
			continue;
		else if (icolumn == 0 && *(*columns + i) <= numberofcolumn) { 
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
			j = icolumn;
			for (j; j + numberofcolumn < *(*columns + i); ++j) 
				*(*(*tab + i) + j) = *(*(*tab + i) + j + numberofcolumn);
			j = icolumn;
			l= 0;
			for (j; j < *(*columns + i) && l < numberofcolumn; ++l, ++j);

			*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) - l) * sizeof(int*));
			*(*columns + i) = *(*columns + i) - l;
		}
	}}

void ISB(unsigned short* rows, unsigned short** columns, int*** tab) {
	unsigned short int irow = 0;
	scanf("%hu", &irow);
	unsigned short int icolumn = 0;
	scanf("%hu", &icolumn);
	unsigned short int numberofrow = 0;
	scanf("%hu", &numberofrow);
	unsigned short int numberofcolumn = 0;
	scanf("%hu", &numberofcolumn);

	if(*rows - 1 < irow) {
		int i = 0;
		for(i = 0; i < numberofrow; i++) {
			int* newrow = (int*)malloc(numberofcolumn * sizeof(int));

			int j = 0, temp = 0;
			for(j = 0; j < numberofcolumn; j++) {		
				scanf("%d", &temp);
				*(newrow + j) = temp;}

			*tab = (int*)realloc(*tab, (*rows + 1) * sizeof(int*));	
			*(*tab + *rows) = newrow;									
			*columns = (unsigned short int*)realloc(*columns, (*rows + 1) * sizeof(unsigned short int));
			*(*columns + *rows) = numberofcolumn;
			*rows = *rows + 1;}}
	else {
		int i = irow, j = 0, temp;
		for(i = 0; i < *rows && j< numberofrow; i++, j++) {
			if(*(*columns + i) <= icolumn) {	
				*(*tab + i) = (int*)realloc(*(*tab + i), (*(*columns + i) + numberofcolumn) * sizeof(int));
				unsigned short int x = *(*columns + i);
				for(x = *(*columns + i); x < *(*columns + i) + numberofcolumn; x++) {
					scanf("%d", &temp);
					*(*(*tab + i) + x) = temp;}
				*(*columns + i) = *(*columns + i) + numberofcolumn;}
			else {
				int* newrow = (int*)malloc((*(*columns + i) + numberofcolumn) * sizeof(int));
				unsigned short int x = 0;
				for (x = 0; x < icolumn; x++) {*(newrow + x) = *(*(*tab + i) + x);}

				unsigned short int l = 0;
				for (l = 0; l < numberofcolumn; l++, x++) {
					scanf("%d", &temp);
					*(newrow + x) = temp;}

                unsigned short int y = x;
				for (y = x; y < *(*columns + i); x++, y++) {*(newrow + x) = *(*(*tab + i) + y);}
				
				free(*(*tab + i));
				*(*tab + i) = newrow;
				*(*columns + i) = *(*columns + i) + numberofcolumn;}}

		for(j = 0; j < numberofrow; j++) {
			int* newrow = (int*)malloc(numberofcolumn * sizeof(int));

			int q = 0, temp = 0;
			for(q = 0; q < numberofcolumn; q++) {		
				scanf("%d", &temp);
				*(newrow + q) = temp;}

			*tab = (int*)realloc(*tab, (*rows + 1) * sizeof(int*));	
			*(*tab + *rows) = newrow;									
			*columns = (unsigned short int*)realloc(*columns, (*rows + 1) * sizeof(unsigned short int));
			*(*columns + *rows) = numberofcolumn;
			*rows = *rows + 1;}}}
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
*/
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
*/
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
