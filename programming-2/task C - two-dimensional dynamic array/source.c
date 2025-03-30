// Anhelina Belavezha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WRF(unsigned short *rows, unsigned short **columns, int ***tab)
{
    char *filename = (char *)malloc(sizeof(char) * 17);
    scanf("%16s", filename);

    if (filename == "")
        return;

    FILE *file = fopen(filename, "wb");

    char rowstring[10];
    sprintf(rowstring, "%d\n", *rows);
    fwrite(rowstring, sizeof(char), strlen(rowstring), file);

    if (*rows != 0)
    {
        int i = 0;
        for (i = 0; i < *rows; i++)
        {
            unsigned short int numcolumns = *(*columns + i);
            char columnstring[10];
            sprintf(columnstring, "%d", numcolumns);
            fwrite(columnstring, sizeof(char), strlen(columnstring), file);

            int j = 0;
            for (j = 0; j < numcolumns; j++)
            {
                int element = *(*(*tab + i) + j);
                char elementstring[20];
                sprintf(elementstring, " %d", element);
                fwrite(elementstring, sizeof(char), strlen(elementstring), file);
            }
            fwrite("\n", sizeof(char), 1, file);
        }
    }
    fclose(file);
    free(filename);
}

void RDF(int ***tab, unsigned short int *rows, unsigned short int **columns)
{
    Clear(rows, columns, tab);

    *tab = NULL;
    *rows = 0;
    *columns = NULL;

    char *filename = (char *)malloc(sizeof(char) * 17);
    scanf("%16s", filename);

    unsigned char symbol = ' ';
    unsigned short numberofrows = 0;

    FILE *file = fopen(filename, "rb");

    while (fread(&symbol, sizeof(char), 1, file) == 1)
    {
        if (symbol == '\n')
            break;
        numberofrows *= 10;
        numberofrows += symbol - '0';
    }

    *rows = numberofrows;
    *tab = (int **)malloc((*rows) * sizeof(int *));
    *columns = (unsigned short int *)malloc((*rows) * sizeof(unsigned short int));

    int i = 0;
    for (i = 0; i < *rows; i++)
    {
        unsigned short int numberofcolumns = 0;
        fread(&numberofcolumns, sizeof(unsigned short int), 1, file);
        *(*columns + i) = numberofcolumns;
        *(*tab + i) = (int *)malloc(numberofcolumns * sizeof(int));
        int j = 0;
        for (j = 0; j < numberofcolumns; j++)
        {
            int element = 0;
            fread(&element, sizeof(int), 1, file);
            *(*(*tab + i) + j) = element;
        }
    }
    fclose(file);
    free(filename);
}

void PRT(int **tab, unsigned short int *rows, unsigned short int *columns)
{
    int i = 0, j = 0;
    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *(columns + i); j++)
        {
            printf("%d ", *(*(tab + i) + j));
        }
        printf("\n");
    }
}

void ISB(int ***tab, unsigned short int *rows, unsigned short int **columns, int **elements, unsigned short int row, unsigned short int column, unsigned short int numberofrow, unsigned short int numberofcolumn) {}

void RMB(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int row, unsigned short int column, unsigned short int numberofrow, unsigned short int numberofcolumn) {}

void RMC(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberofcolumn) {}

void RMR(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberofrow) {}

void DLC(int ***tab, unsigned short int *rows, unsigned short int **columns) {}

void DFC(int ***tab, unsigned short int *rows, unsigned short int **columns) {}

void DLR(int ***tab, unsigned short int *rows, unsigned short int **columns) {}

void SWC(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberoffirstcolumn, unsigned short int numberofsecondcolumn) {}

void SWR(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberoffirstcolumn, unsigned short int numberofsecondcolumn) {}

void IAC(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements, unsigned short int numberofcolumn) {}

void IBC(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements, unsigned short int numberofcolumn) {}

void IAR(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements, unsigned short int numberofrow) {}

void IBR(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements, unsigned short int numberofrow) {}

void ALC(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements) {}

void AFC(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements) {}

void MYALR(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberofelements)
{
    int **newtab = (int **)malloc((*rows + 1) * sizeof(int *));
    *(newtab + *rows) = (int *)malloc(numberofelements * sizeof(int));

    int i;
    for (i = 0; i < *rows; i++)
    {
        *(newtab + i) = *(*(tab) + i);
    }

    unsigned short int *newcolumns = malloc((*rows + 1) * sizeof(unsigned short int));
    *(newcolumns + *rows) = numberofelements;

    for (i = 0; i < *rows; i++)
    {
        *(newcolumns + i) = *(*(columns) + i);
    }

    free(*columns);
    *columns = newcolumns;
    free(*tab);
    *tab = newtab;

    *rows += 1;
}

void ALR(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements)
{
    MYALR(tab, rows, columns, numberofelements);
    int i;
    for (i = 0; i < numberofelements; i++)
    {
        *(*(*(tab) + *rows - 1) + i) = *(elements + i);
    }
}

void MYAFR(int ***tab, unsigned short int *rows, unsigned short int **columns, unsigned short int numberofelements)
{
    int **newtab = (int **)malloc((*rows + 1) * sizeof(int *));
    *(newtab) = (int *)malloc(numberofelements * sizeof(int));

    int i = 0;
    for (i = 0; i < *rows; i++)
    {
        *(newtab + i + 1) = *(*(tab) + i);
    }

    unsigned short int *newcolumns = malloc((*rows + 1) * sizeof(unsigned short int));
    *newcolumns = numberofelements;

    for (i = 0; i < *rows; i++)
    {
        *(newcolumns + i + 1) = *(*(columns) + i);
    }

    free(*columns);
    *columns = newcolumns;
    free(*tab);
    *tab = newtab;

    *rows += 1;
}

void AFR(int ***tab, unsigned short int *rows, unsigned short int **columns, int *elements, unsigned short int numberofelements)
{
    MYAFR(tab, rows, columns, numberofelements);
    int i;
    for (i = 0; i < numberofelements; i++)
    {
        *(*(*(tab) + 0) + i) = *(elements + i);
    }
}

void MYDFR(int ***tab, unsigned short int *rows, unsigned short int **columns, int row)
{
    if (*rows < 1)
        return;
    if (*rows <= row)
        return;

    int **newtab = (int **)malloc((*rows - 1) * sizeof(int *));
    unsigned short int *newcolumns = malloc((*rows + 1) * sizeof(unsigned short int));

    int i = 0, j = 0;
    for (i = 0, j = 0; i < *rows; i++, j++)
    {
        if (i == row)
        {
            j--;
        }
        else
        {
            *(newtab + j) = *(*(tab) + i);
            *(newcolumns + j) = *(*(columns) + i);
        }
    }

    free(*(*(tab) + row));
    free(*tab);
    free(*columns);
    *rows -= 1;
    *tab = newtab;
    *columns = newcolumns;
}

void DFR(int ***tab, unsigned short int *rows, unsigned short int **columns)
{
    MYDFR(tab, rows, columns, 0);
}

int main()
{
    unsigned short int *rows = malloc(sizeof(unsigned short int));
    *rows = 0;
    unsigned short int *columns = malloc(*rows * sizeof(unsigned short int));
    int **tab = (int **)malloc(*rows * sizeof(int *));
    char *operation = malloc(4 * sizeof(char));

    scanf("%s", operation);

    while (strcmp(operation, "END") != 0)
    {

        if (strcmp(operation, "AFR") == 0)
        {
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            AFR(&tab, rows, &columns, elements, numberofelements);
            free(elements);
        }

        else if (strcmp(operation, "ALR") == 0)
        {
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            ALR(&tab, rows, &columns, elements, numberofelements);
            free(elements);
        }

        else if (strcmp(operation, "AFC") == 0)
        {
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            AFC(&tab, rows, &columns, elements, numberofelements);
            free(elements);
        }

        else if (strcmp(operation, "ALC") == 0)
        {
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            ALC(&tab, rows, &columns, elements, numberofelements);
            free(elements);
        }

        else if (strcmp(operation, "IBR") == 0)
        {
            unsigned short int numberofrow;
            scanf("%i", &numberofrow);
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            IBR(&tab, rows, &columns, elements, numberofelements, numberofrow);
            free(elements);
        }

        else if (strcmp(operation, "IAR") == 0)
        {
            unsigned short int numberofrow;
            scanf("%i", &numberofrow);
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            IAR(&tab, rows, &columns, elements, numberofelements, numberofrow);
            free(elements);
        }

        else if (strcmp(operation, "IBC") == 0)
        {
            unsigned short int numberofcolumn;
            scanf("%i", &numberofcolumn);
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            IBC(&tab, rows, &columns, elements, numberofelements, numberofcolumn);
            free(elements);
        }

        else if (strcmp(operation, "IAC") == 0)
        {
            unsigned short int numberofcolumn;
            scanf("%i", &numberofcolumn);
            unsigned short int numberofelements;
            scanf("%i", &numberofelements);
            int *elements = malloc(numberofelements * sizeof(int));
            int i = 0;
            for (i = 0; i < numberofelements; i++)
            {
                scanf("%i", elements + i);
            }
            IAC(&tab, rows, &columns, elements, numberofelements, numberofcolumn);
            free(elements);
        }

        else if (strcmp(operation, "SWR") == 0)
        {
            unsigned short int numberoffirstrow;
            scanf("%i", &numberoffirstrow);
            unsigned short int numberofsecondrow;
            scanf("%i", &numberofsecondrow);
            SWR(&tab, rows, &columns, numberoffirstrow, numberofsecondrow);
        }

        else if (strcmp(operation, "SWC") == 0)
        {
            unsigned short int numberoffirstcolumn;
            scanf("%i", &numberoffirstcolumn);
            unsigned short int numberofsecondcolumn;
            scanf("%i", &numberofsecondcolumn);
            SWC(&tab, rows, &columns, numberoffirstcolumn, numberofsecondcolumn);
        }

        else if (strcmp(operation, "DFR") == 0)
        {
            DFR(&tab, rows, &columns);
        }

        else if (strcmp(operation, "DLR") == 0)
        {
            DLR(&tab, rows, &columns);
        }

        else if (strcmp(operation, "DFC") == 0)
        {
            DFC(&tab, rows, &columns);
        }

        else if (strcmp(operation, "DLC") == 0)
        {
            DLC(&tab, rows, &columns);
        }

        else if (strcmp(operation, "RMR") == 0)
        {
            unsigned short int numberofrow;
            scanf("%i", &numberofrow);
            RMR(&tab, rows, &columns, numberofrow);
        }

        else if (strcmp(operation, "RMC") == 0)
        {
            unsigned short int numberofcolumn;
            scanf("%i", &numberofcolumn);
            RMC(&tab, rows, &columns, numberofcolumn);
        }

        else if (strcmp(operation, "RMB") == 0)
        {
            unsigned short int row;
            scanf("%i", &row);
            unsigned short int numberofrow;
            scanf("%i", &numberofrow);
            unsigned short int column;
            scanf("%i", &column);
            unsigned short int numberofcolumn;
            scanf("%i", &numberofcolumn);
            RMB(&tab, rows, &columns, row, column, numberofrow, numberofcolumn);
        }

        else if (strcmp(operation, "ISB") == 0)
        {
            unsigned short int row;
            scanf("%i", &row);
            unsigned short int column;
            scanf("%i", &column);
            unsigned short int numberofrow;
            scanf("%i", &numberofrow);
            unsigned short int numberofcolumn;
            scanf("%i", &numberofcolumn);
            int **elements = (int **)malloc(numberofrow * sizeof(int *));
            int i = 0;
            for (i = 0; i < numberofrow; i++)
            {
                *(elements + i) = (int *)malloc(numberofcolumn * sizeof(int));
                int j;
                for (j = 0; j < numberofcolumn; j++)
                {
                    scanf("%i", (*(elements + i) + j));
                }
            }
            ISB(&tab, rows, &columns, elements, row, column, numberofrow, numberofcolumn);
            for (i = 0; i < numberofrow; i++)
            {
                free(*(elements + i));
            }
            free(elements);
        }

        else if (strcmp(operation, "WRF") == 0)
        {
            WRF(&tab, rows, &columns);
        }

        else if (strcmp(operation, "RDF") == 0)
        {
            RDF(&tab, rows, &columns);
        }

        else if (strcmp(operation, "PRT") == 0)
        {
            PRT(tab, rows, columns);
        }

        fflush(stdin);
        scanf("%s", operation);
    }

    while (*rows != 0)
    {
        DFR(&tab, rows, &columns);
    }

    free(tab);
    free(operation);
    free(rows);
    free(columns);
    return 0;
}
