
/*
 * Greetings:
 * A program to demonstrate using
 * signals and signal handlers
 */

#include <stdio.h>
#include <signal.h>     // Required to handle signals
#include <stdlib.h>

void diediedie(int sig);
int catch_signal(int sig, void (*handler)(int));


// This is our new signal handler:
void diediedie(int sig)     // The OS passes the signal to the handler
{
    puts("Goodbye, cruel world...\n");
    exit(1);
}

// This is the function to register a signal handler:
int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main()
{
    // SIGINT means we're capturing the INTERRUPT signal
    if (catch_signal(SIGINT, diediedie) == -1) {            // diediedie sets the interrupt handler
        fprintf(stderr, "Unable to map the handler...");    // to the diediedie() function
        exit(2);
    }
    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);
    return 0;
}
