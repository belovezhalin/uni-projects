//Anhelina Belavezha grupa nr 3
#include <unistd.h>  
#include <fcntl.h>                                               //biblioteka do flagi creat

int podziel(const char *file) {
    int input = open(file, O_RDONLY);
    int output1 = open("fragment1", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int output2 = open("fragment2", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if(input == -1) return -1;
    if(output1 == -1) return -1;
    if(output2 == -1) return -1;

    int size = 0;
    char buf[1];
    int bytes = 1;
    int newbyte = 0;

    while(bytes > 0) {                                          //odczyt pliku wejsciowego
        bytes = read(input, buf, 1);
        size += bytes;
        if(bytes == -1)return -1;
    }

    close(input);
    input = open(file, O_RDONLY);

    if(size % 2 == 0) {                                         //parzysty rozmiar
        while(newbyte < size) {
            if(size/2 > newbyte) {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output1, buf, bytes);
                newbyte += bytes;
            }
            else {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output2, buf, bytes);
                newbyte += bytes;}}}
    else {                                                      //nieparzysty rozmiar
        while(newbyte < size) {
            if(size/2 + 1 <= newbyte) {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output2, buf, bytes);
                newbyte += bytes;}
            else {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output1, buf, bytes);
                newbyte += bytes;}}}

    close(input);
    close(output1);
    close(output2);
    return 0;
}
/*
int main() {
const char* file = "input.txt"; 
int result = podziel(file);
return 0;
}*/
