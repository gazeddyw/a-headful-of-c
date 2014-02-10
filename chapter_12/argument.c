
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>    // Header for the POSIX thread library


void* does_not(void *a)
{
    int i = 0;
    for (i = 0; i < 5; i++) {
        sleep(1);
        puts("Does not!");
    }
    return NULL;
}

void* does_too(void *a)
{
    int i = 0;
    for (i = 0; i < 5; i++) {
        sleep(1);
        puts("Does too!");
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
    // Records all the information about the threads
    pthread_t t0;
    pthread_t t1;
    
    // pthread_create() creates the thread
    // &tN is the address of the the data structure
    // that will store the thread information
    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Unable to create thread t0");
    
    // does_not / does_too are the names of
    // the functions the threads will run
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("Unable to create thread t1");
    
    
    void* result;
    if (pthread_join(t0, &result) == -1)
        error("Unable to join thread t0");
    
    if (pthread_join(t1, &result) == -1)
        error("Unable to join thread t1");
    
    return 0;
}
