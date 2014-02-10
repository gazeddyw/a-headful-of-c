
/*
 * food_scanf_fgets uses fgets() to replace scanf()
 * 
 * Chapter 2, Head First C
 * 
 */

#include <stdio.h>

int main() {
    
    printf("\n");
    
    char food[5];
    printf("Enter favourite food: ");
    // scanf("%s", food); // this can be replaced with fgets() to eliminate segmentation fault
    fgets(food, sizeof(food), stdin);
    printf("Favourite food is: %s\n", food);
    
    printf("\n");
    
    return 0;
    
}
