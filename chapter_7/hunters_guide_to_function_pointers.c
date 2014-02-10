
/*
 * Hunter's Guide To Function Pointers
 * 
 * Prints a guide to using function pointers
 * 
 */


#include <stdio.h>


int main()
{
    puts("\n");
    
    printf("\tReturn type (* Pointer variable )( Param types )\n");
    printf("\t     ^       ^        ^                 ^       \n");
    printf("\t   char**    `-- (*names_fn)      (char*, int)  \n");
    
    puts("\n");
    return 0;
}
