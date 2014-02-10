
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>    // Header for the POSIX thread library

int beers = 2000000;

void* do_stuff(void *param)
{
    // Cast the void pointer to a long
    long thread_no = (long)param;
    printf("Thread number %ld\n", thread_no);
    
    // Cast it back to a void pointer when it is returned
    return (void*)(thread_no + 1);
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char *argv[])
{
    pthread_t threads[20];
    long t;
    
    // LONG values can be passed to thread functions,
    // because they are the SAME SIZE in memory
    for (t = 0; t < 3; t++) {
                                    // Cast the long value \/ to a void pointer
        if (pthread_create(&threads[t], NULL, do_stuff, (void*)t) == -1)
            error("Unable to create thread");
    }
    
    void* result;
    for (t = 0; t < 3; t++) {
        if (pthread_join(threads[t], &result) == -1)
            error("Unable to join thread");     // Cast return value to a long
        printf("Thread %ld returned %ld\n", t, (long)result);
    }
    
    return 0;
}
