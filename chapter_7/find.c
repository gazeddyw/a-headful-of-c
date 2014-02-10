
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
    "Luis: SLM ND likes books, theatre art",
    "Mike: DWM DS likes trucks, sports, and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theatre",
    "Jed: DBM likes theatre, books and dining"
};


// Needs \/ FUNCTION POINTERS TO PASS CODE TO THE FIND FUNCTION
void find()
{
    int i;
    puts("Searching...\n");
    puts("Search results:");
    puts(LINE);
    
    for (i = 0; i < NUM_ADS; i++)
    {
	if (strstr(ADS[i], "art") || strstr(ADS[i], "theatre") || strstr(ADS[i], "dining"))
	{
	    printf("%s\n", ADS[i]);
	}
    }
    puts(LINE);
}


int main()
{
    puts("");
    
    find();
    
    puts("");
    
    return 0;
}
