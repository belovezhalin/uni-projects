//Anhelina Belavezha
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if(argc == 3) {
    if (sscanf(argv[1], "%d", &sierot) == 1 && sscanf(argv[2], "%d", &zombie) == 1) {
    int i = 0; 

    for(i = 0; i < sierot; i++) {                                //tworzenie procesow sierot
        if (fork() == 0) {
            printf("PID sieroty %d ParentID %d\n", getpid(), getppid());
            sleep(10);
            exit(EXIT_SUCCESS);}}

    for(i = 0; i < zombie; i++) {                               //tworzenie procesow zombie
        if (fork() == 0) {
            exit(EXIT_SUCCESS);}}

    for(i = 0; i < sierot + zombie; i++) {                      //czekanie na procesy potomne
        wait(NULL);
        printf("PID zombie %d ParentID %d\n", i + 1, getppid());}

    return 0;}}

    else return -1;
}