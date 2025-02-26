#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;
    char buf[1024];
    char message[100];
    const char* TOSERVER = "toserver";
    const char* FROMSERVER = "fromserver";

    mkfifo(TOSERVER, 0666);                                             //tworzenie fifo
    mkfifo(FROMSERVER, 0666);

    if ((fd = open(TOSERVER, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    while (10000) {                                                     //przyjecie polecen od wiecej niz jednego klienta
        read(fd, message, sizeof(message));
        if (message[0] != '\0') {
            FILE *fp = popen(message, "r");                             //pipe
            size_t nread = fread(buf, 1, sizeof(buf) - 1, fp);
            buf[nread] = '\0';
            pclose(fp);
            printf("Rezultat: %s\n", buf);
            int answer = open(FROMSERVER, O_WRONLY);
            write(answer, buf, strlen(buf) + 1);
            close(answer);
        }
    }
    close(fd);
    unlink(TOSERVER);
}