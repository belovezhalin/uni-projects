#include <pthread.h>
#include <stdio.h>

#define LiczbaWatkow 10 // <- do ew. zmiany

long suma = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *dodaj(void *arg) {
    int ile = *((int *)arg);
    for(int i=0; i<ile; i++) {
        pthread_mutex_lock(&mutex);
        suma++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    long liczby[LiczbaWatkow];
    long oczekiwanaSuma = 0;

    pthread_t watki[LiczbaWatkow];
    int parametry[LiczbaWatkow];

    for(int i=0; i<LiczbaWatkow; i++) {
        liczby[i] = 300000; // <- do ew. zmiany
        oczekiwanaSuma += liczby[i];
        parametry[i] = liczby[i];
        pthread_create(&watki[i], NULL, dodaj, &parametry[i]);
    }
    for(int i=0; i<LiczbaWatkow; i++) {
        pthread_join(watki[i], NULL);
    }

    printf("Obliczona suma: %ld (oczekiwana wartość: %ld)\n", suma, oczekiwanaSuma);
    return 0;
}
