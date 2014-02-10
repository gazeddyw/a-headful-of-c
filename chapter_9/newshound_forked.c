
/*
 * Newshound... Forked :-
 * 
 * Calls a Python script to search RSS feeds
 * using a search term
 * 
 * fork() is used to create a child process,
 * then execle() to call the Python program
 */


#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *feeds[] = {"http://www.linuxplanet.com/rss",
                     "http://www.osnews.com/files/recent.xml",
                     "http://www.linux.com/feeds/all-content"};
    
    int times = 3;
    char *phrase = argv[1];
    int i;
    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        
                                // FORK the process - Create a child process
        pid_t pid = fork();     // fork() returns the Process ID of the child process for the parent
                                // It returns ZERO for the child process
        
        if (pid == -1) {
            fprintf(stderr, "Unable to fork process: %s\n", strerror(errno));
            return 1;
        }
        
        if (!pid) {
            if (execle("/usr/bin/python", "/usr/bin/python",
                    "./rss_gossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Unable to run script: %s", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}
