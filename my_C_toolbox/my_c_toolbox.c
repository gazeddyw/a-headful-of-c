
/*
 * My C Toolbox allows the user to print out the toolbox at the end
 * of the chapter of their choice, from Head First C.
 * 
 * (c) Gareth Williams, 2013
 */

// Header files to be included
#include <stdio.h>

// Definitions to be used in the program
#define LINE "===================" 


/* 
 * printHeading() prints out a heading at the top of the app
 */
void printHeading() {
    
    printf("\n");
    printf(" " LINE "\n");
    printf("  My C Toolbox v1.0\n");
    printf(" " LINE "\n\n");
}
//////////////////////////////


int main() {
    
    int chapterNum = 0;
    
    printHeading();
    chapterNum = getChapter();
    //printf("chapterNum is: %d\n", chapterNum);
    printChapter(chapterNum);
    
    printf("\n");
    
    return 0;
    
}
