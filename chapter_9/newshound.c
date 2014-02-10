
/*
 * Newshound :-
 * 
 * Calls a Python script to search RSS feeds
 * using a search term
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
        if (execle("/usr/bin/python", "/usr/bin/python",
                "./rss_gossip.py", phrase, NULL, vars) == -1) {
            fprintf(stderr, "Nope: %s", strerror(errno));
            return 1;
        }
    }
    
    return 0;
}
