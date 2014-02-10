
/*
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE "----------------------------------"


int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theatre",
    "Luis: SLM ND likes books, theatre, art",
    "Mike: DWM DS likes trucks, sports, and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theatre",
    "Jed: DBM likes theatre, books and dining"
};


int sports_no_bieber(char *s)
{
    return strstr(s, "sports") && !strstr(s, "bieber");
}


int sports_or_workout(char *s)
{
    return strstr(s, "sports") || strstr(s, "working out");
}


int ns_theatre(char *s)
{
    return strstr(s, "NS") && strstr(s, "theatre");
}


int arts_theatre_or_dining(char *s)
{
    return strstr(s, "art") || strstr(s, "theatre") || strstr(s, "dining");
}


// Pass the find function A POINTER TO A FUNCTION
void find( int(*match)(char*) )
{
    int i;
    
    puts("\nSearch results:");
    puts(LINE);
    
    for (i = 0; i < NUM_ADS; i++)
    {
	if (match(ADS[i]))
	{
	    printf("%s\n", ADS[i]);
	}
    }
    puts(LINE);
}


int main()
{
    puts("");
    
    puts("Searching...");
    find(sports_no_bieber);
    find(sports_or_workout);
    find(ns_theatre);
    find(arts_theatre_or_dining);
    
    puts("");
    
    return 0;
}
