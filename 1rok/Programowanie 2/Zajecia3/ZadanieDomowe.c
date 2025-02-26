#include <stdlib.h>
#include <stdio.h>

#define inputname "krakow.bmp"
#define outputname "change.bmp"

int main() {
    FILE* input = fopen(inputname, "rb");                    //tryb odczytu pliku binarnego (pliki graficzne, dzwiekowe)
    if (input == NULL) {
        printf("Blad otwarcia pliku wejsciowego!");
        return 1;}

    FILE* output = fopen(outputname, "wb");                  //tryb zapisu pliku binarnego (pliki graficzne, dzwiekowe)
    if (output == NULL) {
        printf("Blad otwarcia pliku wyjsciowego!");
        return 1;}

    unsigned char header[54];                                //naglowek bmp ma rozmiar 54 bajty(14 bajtow przechowuja naglowek, 40 bajtow przechowuja informacje o obrazie)
    fread(header, sizeof(unsigned char), 54, input);
    fwrite(header, sizeof(unsigned char), 54, output);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;                 // 3 - liczba bajtow na piksel w BMP, kazda linia obrazu konczy sie 4 bajtami
                          
    unsigned char pixel[3];
    
    for(int row = 0; row < height; row++) {
       for (int column = 0; column < width; column++) {
         fread(pixel, sizeof(unsigned char), 3, input);
         pixel[0] = 255;                                     //ustawienie koloru
         fwrite(pixel, sizeof(unsigned char), 3, output);}
        fseek(input, padding, SEEK_CUR);                     //pominiecie paddingu w wierszu
        for (int i = 0; i < padding; fputc(0x00, output), i++);} //fputc - zapis pojedynczego znaku do pliku (dodawanie paddingu)
       
    fclose(input);                                           //zamkniecie plikow
    fclose(output);

    printf("Koniec dzialania!");
    return 0;
}