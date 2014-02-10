
/*
 * Maths Skills
 * This program tests a users' maths skills and
 * keeps track of how many answers they got right
 * 
 * TO DO: Modify the game so that it takes
 * command line args for time delay in seconds,
 * type of questions to ask, number range etc.
 * 
 * e.g. 3 second limit for addition problems for numbers between 1 & 20.
 *      10 second limit for division problems
 *      programming problems??
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void end_game(int sig)
{
    printf("\nFinal Score: %d\n\n", score);
    exit(0);
}

void times_up(int sig)
{
    puts("\n\n\nTIME'S UP!!");
    raise(SIGINT);  // Escalates the SIGALRM to a SIGINT after TIME'S UP!! is displayed
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}



int main()
{
    if (catch_signal(SIGALRM, times_up) == -1) {
        error("Unable to map SIGALRM handler...");
    }
    if (catch_signal(SIGINT, end_game) == -1) {
        error("Unable to map SIGINT handler...");
    }
    
    srandom(time(0));   // Make sure you get different random numbers each time
    
    while(1) {
        
        int a = random() % 11;  // a and b will be random
        int b = random() % 11;  // numbers from 0 to 10
        alarm(5);   // If 5 secs pass, a SIGALRM is sent
        char txt[4];
        do {
            printf("\nWhat is %d x %d? ", a, b);
            fgets(txt, 4, stdin);
            int answer = atoi(txt);
            if (txt[0] == '\n') {
                printf("\n\nEnter an answer...\n");
                continue;
            }
            else if (answer == a * b)
                score++;
            else
                printf("\n\nWrong! Score: %d\n", score);
        } while (txt[0] == '\n');
    }
    return 0;
}

    