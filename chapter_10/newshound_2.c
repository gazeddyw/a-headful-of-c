
/*
 * Newshound... 2 :-
 * 
 * Calls a Python script to search RSS feeds
 * using a search term
 * 
 * fork() is used to create a child process,
 * then execle() to call the Python program
 * 
 * dup2() function is used in the code so
 * that std output will be redirected from 
 * std out (screen) to the file "stories.txt"
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg);


int main(int argc, char *argv[])
{
    
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/science_and_environment/rss.xml", NULL};
    
    FILE *f = fopen("stories.txt", "w");
    if (!f) {
        error("Unable to open stories.txt");    // sends errors to the new error() function
    }
    
        
                            // FORK the process - Create a child process
    pid_t pid = fork();     // fork() returns the Process ID of the child process for the parent
                            // It returns ZERO for the child process
        
    if (pid == -1) {
        error("Unable to fork process");
    }
        
    if (!pid) {                                         // dup2() points file descriptor #1 (std output)
        if (dup2(fileno(f), 1) == -1) {                 // to the text file "stories.txt" (pointed to by f)
            error("Unable to redirect Standard Out");
        }
        if (execle("/usr/bin/python", "/usr/bin/python",
                "./rss_gossip.py", phrase, NULL, vars) == -1) {
            error("Unable to run script");
        }
    }
    
    int pid_status;                                 // waitpid() will NOT return until the child process dies
    if (waitpid(pid, &pid_status, 0) == -1) {       // In this case, it will not exit until the 
        error("Error waiting for child process");   // rss_gossip.py script has stopped running
    }
    
    return 0;
}


void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);    // exit(1) will terminate the program with status 1 IMMEDIATELY! Program does not return to main().
}
