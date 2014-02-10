
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>    // Header for the POSIX thread library

int beers = 2000000;

void* drink_lots(void *a)
{
    int i;
    for (i = 0; i < 100000; i++) {
        beers -= 1;
    }
    return NULL;
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


/*** WARNING - This code is not THREAD-SAFE ***/
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
