#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/wait.h>

int main() {
    fork();
    printf("PID: %d\n", getpid());
    return 0;}
//PID: 28478
//PID: 28479

int main() {
    if(fork() == 0) printf("PID potomny: %d\n", getpid());
    else printf("PID macierzysty: %d\n", getpid());
    return 0;}
//PID macierzysty: 28478
//PID potomny: 28479                  //kolejnosc nie jest konieczna, moze by odwrotnie

/*
Przykład. Napisać program, który uruchomi 16 procesów potomnych.
Każdy z nich powinien wypisać swój numer PID, numer PID procesu
macierzystego oraz liczbę z przedziału od 1 do 16 (każdy inną).*/

int main() {
    for(int i = 1; i < 16; i++) {
    if(fork() == 0) {
        printf("Proces: %d, PID potomny: %d, PID macierzysty: %d\n", i, getpid(), getppid());
        return 0;}
    for(int i = 1; i <= 16; i++) {wait(NULL);}
    return 0;}

/*
Przykład. Uruchomić polecenie find w celu znalezienia w katalogu /usr
wszystkich plików o rozmiarze ponad 1MB. Zakończyć utworzony proces.
find / -size +1M -type f 

priorytet: 
-10 - pierwsze 
0
10

nice (NI):
-20..20
-20 - proces "niemily",, nie da innym procesom korzystac ze swojego czasu

nice, renice (zmiana milych procesorow)

h -> help
shift + F -> ustalenie kolumn
s -> sortowanie
p -> ostatnio uzywany procesor[0..5]
shift + R -> sortowanie wedlug(?)

zatrzymanie procesora: ctrl + Z
zakonczenie procesora: ctrl + C 
*/