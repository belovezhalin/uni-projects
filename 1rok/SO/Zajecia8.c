#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *f(void *arg) {
    int numer = *((int *)arg);
    printf("Watek numer: %d\n", numer);
    sleep(1);
    int temp = numer + 1;
    return (void*)&temp;
}

int main() {
    pthread_t id[8];
    int num[8];
    for(int i = 0; i < 8; i++) {
        num[i] = i + 1;
        pthread_create(&id[i], NULL, f, NULL);
        //printf("Utworzony watek id: %ld\n", id);
    }
    for(int i = 0; i < 8; i++) {
        pthread_join(id[i], NULL);
        //printf("Zakonczony watek id: %ld\n", id);
    }
    return 0;
}