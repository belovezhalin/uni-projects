#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    int fd;
    char buf[1024];
    char message[100];
    const char* TOSERVER = "toserver";
    const char* FROMSERVER = "fromserver";

    if ((fd = open(TOSERVER, O_WRONLY)) == -1) {
        perror("open");
        exit(1);
    }

    while (10000) {
        printf("Napisz polecenie do wykonania(lub '\0' zeby zakonczyc): ");
        fgets(message, sizeof(message), stdin);

        if (message[strlen(message) - 1] == '\n') {                    //usuniecie enter na koncu polecenia
            message[strlen(message) - 1] = '\0';
        }

        if (write(fd, message, strlen(message) + 1) == -1) {           //wysylanie polecenia
            perror("write");
            exit(1);
        }

        if (message[0] == '\0') {                                      //koniec dzialania 
            break;
        }

        int answer = open(FROMSERVER, O_RDONLY);                      //odczytanie odpowiedzi 
        read(answer, buf, sizeof(buf));
        close(answer);
        printf("Odpowiedz:%s\n", buf);
    }

    close(fd);
    printf("Koniec dzialania klienta!\n");

    return 0;
}
