
#include <stdio.h>

/* 
 * getChapter() asks the user to select a chapter toolbox to display
 */
int getChapter() {
    
    const int maxChapter = 12;
    const int minChapter = 1;
    int chNum = 0;
    while ((chNum < minChapter) || (chNum > maxChapter)) {
	printf("Please enter the chapter you would like to display: ");
	if (scanf("%d", &chNum) < 1) {
	    fprintf(stderr, "\nError: Invalid chapter selection...\n");
	    chNum = 0;
	    break;
	}
	else if ((chNum < minChapter) || (chNum > maxChapter)) {
	    printf("Please enter a chapter between %d and %d\n", minChapter, maxChapter);
	}
	else {
	    printf("Chapter %d selected\n", chNum);
	}
    }
    
    return chNum;
}
//////////////////////////////
