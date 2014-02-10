
/*
 * A program to search for text in song names
 * 
 * (c) Gareth Williams 2013 
 */

#include <stdio.h>
#include <string.h>

char tracks[][80] = {
    "I Left My Heart In Here",
    "Newark, Newark - A Wonderful Town",
    "Dancing With A Dork",
    "From Here To Maternity",
    "The Girl From Iwo Jima",
};

void findTrack(char search_for[]) {
    
    int i;
    int trackMatch = 0;
    for (i = 0; i < 5; i++) {
	if (strcasestr(tracks[i], search_for)) {
	    printf("Track %d: '%s'\n", i, tracks[i]);
	    trackMatch++;
	}
    }
    if (trackMatch == 0) {
	printf("Search string '%s' not found...\n", search_for);
    }
}

int main() {
    
    char search_for[80];
    printf("Search for: ");
    scanf("%79s", search_for);
    findTrack(search_for);
    return 0;
    
}
