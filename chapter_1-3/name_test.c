
/*
 * name_test uses scanf() to take in two pieces of info
 * Chapter 2, Head First C
 * 
 */

#include <stdio.h>

int main() {
    
    printf("\n");
    
    char first_name[20];
    char last_name[20];
    int age;
    
    printf("Enter full name: ");
    scanf("%19s %19s", first_name, last_name);
    
    printf("Enter age in years: ");
    scanf("%d", &age);
    printf("\nFirst name: %s, Last name: %s\n", first_name, last_name);
    printf("Age: %d\n", age);
    
    printf("\n");
    
    return 0;
    
}
