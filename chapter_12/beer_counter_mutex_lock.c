
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>    // Header for the POSIX thread library

#define VERSION 2


int beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER; // A Macro!

void* drink_lots(void *a)
{
    int i;
    if (VERSION == 1) {
        pthread_mutex_lock(&beers_lock);
        for (i = 0; i < 100000; i++) {
            beers -= 1;
        }
        pthread_mutex_unlock(&beers_lock);
        printf("beers = %d\n", beers);
    }
    if (VERSION == 2) {
        
        for (i = 0; i < 100000; i++) {
            pthread_mutex_lock(&beers_lock);
            beers -= 1;
            pthread_mutex_unlock(&beers_lock);
        }
        printf("beers = %d\n", beers);
    }
    return NULL;
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char *argv[])
{
    pthread_t threads[20];
    int t;
    
    printf("%d bottles of beer on the wall\n%d bottles of beer\n", beers,
           beers);
    
    // Create 20 threads that run the drink_lots function
    for (t = 0; t < 20; t++) {
        if (pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
            error("Unable to create thread t0");
    }
    
    void* result;
    for (t = 0; t < 20; t++) {
        pthread_join(threads[t], &result);
    }
    
    printf("There are now %d bottles of beer on the wall\n", beers);
    
    return 0;
}
