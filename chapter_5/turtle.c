
/*
 * 
 * 
 */


#include <stdio.h>


typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;


void happy_birthday(turtle *t) { // A pointer must be passed to the function in order to update values!
    
    // t->age is a simpler notation for (*t).age - they are equivalent
    t->age = (*t).age + 1; // (*t).age != *t.age - Parentheses are required as t.age is not a memory location
    printf("Happy Birthday %s! You are now %d years old!\n", (*t).name, t->age);
    
}


int main() {
    
    turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    
    happy_birthday(&myrtle); // The address of myrtle (&) must be passed to happy_birthday()
    
    printf("%s's age is now %d.\n", myrtle.name, myrtle.age);
    
    return 0;
}
