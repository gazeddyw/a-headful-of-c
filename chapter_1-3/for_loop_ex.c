
/*
 * An example 'for' loop
 * 
 * 
 */

#include <stdio.h>

int main() {
    
    puts("");
    
    int z;
    int y;
    int x;
    // A chained assignment
    z = y = x = 3; // Variables must be declared first
    
    int loop;
    
    for (loop = 0; loop < 5; loop++) {
	printf("Loop iteration: %d\n", loop);
	
	if (loop == 3) {
	    break;
	}
    }
    
    printf("\nResult of chained assignment:\n");
    printf("\t%i\n\t%i\n\t%i\n", x, y, z);
    
    puts("");
    
    return 0;
}
