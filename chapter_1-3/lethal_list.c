
/*
 * The Lethal List 5 minute mystery
 * Chapter 2, Head First C
 * 
 */

#include <stdio.h>

int main() {
    
    printf("\n");
    
    int doses[] = {1, 3, 2, 1000};
    printf("Issue dose %d\n", 3[doses]); // The same as coding doses[3] ! ! !
    printf("Issue dose %d\n", doses[3]); // Will issue a dose of 1000 ! ! !
    
    printf("Issue dose %d\n", *(doses + 1)); // Prints the 2nd array element
    
    printf("\n");
    
    return 0;
    
}
