
/*
 * Comparator Test
 * 
 * Examples of using comparators to sort data into order
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comparator_funcs.h"


int main()
{
    puts("");
    
    int scores[] = {543,323,32,554,11,3,112};
    int i;
    
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    
    puts("These are the scores in order:");
    
    for (i = 0; i < 7; i++)
    {
	printf("Score = %d\n", scores[i]);
    }
    
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);
    
    puts("These are the names in order:");
    
    for (i = 0; i < 4; i++)
    {
	printf("%s\n", names[i]);
    }
    
    puts("");
    return 0;
}
