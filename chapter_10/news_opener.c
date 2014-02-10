
/*
 * News Opener :-
 * 
 * Calls a Python script to search, then open
 * RSS feeds in a web browser on the system
 * 
 * pipe() is used to communicate between the
 * parent and child processes in real time
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg);
void open_url(char *url);


int main(int argc, char *argv[])
{
    
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/science_and_environment/rss.xml", NULL};
    
    int fd[2];
    if (pipe(fd) == -1) {
        error("Unable to create pipe");
    }
        
                            // FORK the process - Create a child process
    pid_t pid = fork();     // fork() returns the Process ID of the child process for the parent
                            // It returns ZERO for the child process
        
    if (pid == -1) {
        error("Unable to fork process");
    }
        
    if (!pid) {
        dup2(fd[1], 1);     // Do some crazy 
        close(fd[0]);       // shit with pipes!
        
        if (execle("/usr/bin/python", "/usr/bin/python",
                "./rss_gossip.py", "-u", phrase, NULL, vars) == -1) {
            error("Unable to run script");
        }
    }
    
    dup2(fd[0], 0);
    close(fd[1]);
    
    char line[255];
    while (fgets(line, 255, stdin)) {
        if (line[0] == '\t')    // If the line starts with a tab...
            open_url(line + 1); // ... then it's a URL
    }           // (line + 1) is the string starting after the tab character
    
    return 0;
}


void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);    // exit(1) will terminate the program with status 1 IMMEDIATELY! Program does not return to main().
}


void open_url(char *url)
{
    char launch[255];
    pid_t pid_browser = fork();
    
    if (pid_browser == -1) {
        error("Unable to fork process");
    }
    if (!pid_browser) {
        
        if (execl("/usr/bin/firefox", "/usr/bin/firefox", url, NULL) == -1) {
            error("Unable to run script");
        }
    }
    
}
