//Anhelina Belavezha gr 3
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    int i;

    for (i = 1; i < argc; i++) {
        filename = argv[i];
        printf("%s:\n", filename);                                            //wypisywanie nazwy pliku

        fp = fopen(filename, "r");                                            //otwarcie aktualnego pliku do odczytu

        if (fp == NULL) {
            fprintf(stderr, "Blad otwarcia pliku %s\n", filename);            //w przypadku braku pliku wywala blad otwarcia
            continue;}

        char buf[1024];                                                       //przechowywanie danych pliku
        size_t nread;
        while ((nread = fread(buf, 1, sizeof(buf), fp)) > 0) {
            if (fwrite(buf, 1, nread, stdout) != nread) {
                fprintf(stderr, "Blad wypisania\n");                          //blad przy wypisywaniu 
                fclose(fp);
                exit(EXIT_FAILURE);}
        }
        if (ferror(fp)) fprintf(stderr, "Blad odczytu pliku %s\n", filename); //w przypadku niemozliwosci odczytania wywala blad odczytu
        fclose(fp);                                                           //zamkniecie pliku
    }
    return 0;
}