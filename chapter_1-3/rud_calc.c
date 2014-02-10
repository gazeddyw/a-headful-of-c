
/*
 * name_test uses scanf() to take in two pieces of info
 * Chapter 2, Head First C
 * 
 */

#include <stdio.h>

int main() {
    
    printf("\n");
    
    float sum = 0;
    float v;
    
    while (scanf("%1f", &v) == 1) {
	printf("\t%.2f\n", sum += v);
    }
    
    printf("\n");
    
    return 0;
    
}
