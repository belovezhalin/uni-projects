#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd[2];

    pipe(fd);
    if(fork() == 0) {
        char bufor[11];
        read(fd[0], bufor, 10);
        int ile = read(fd[0], bufor, 10);
        bufor[ile] = 0;
        printf("Odczytane: %s\n", bufor);
    }
    else {
        sleep(1);
        write(fd[1], "OK!", 3);
    }
    return 0;
}