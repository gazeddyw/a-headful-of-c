
/*
 * An example of using structs and typedef
 * 
 * 
 */

#include <stdio.h>


typedef struct {	// structs do not have to be named when using typedef
    const char *name;
    const char *species;
    int teeth;
    int age;
} fish; // Must have a semicolon here! The alias for this struct is 'fish'


/* Print out the catalog entry */
void catalog(fish f) {
    
    // struct fields are referenced using 'dot notation' <struct>.<fieldname>
    printf("%s is a %s with %d teeth. He is %d.\n", f.name, f.species, f.teeth, f.age);
    
}

/* Print the label for the tank */
void label(fish f) {
    
    printf("Name: %s\n", f.name);
    printf("Species: %s\n", f.species);
    printf("%d years old, %d teeth\n", f.age, f. teeth);
    
}


int main() {
    
    fish snappy = {"Snappy", "Piranha", 69, 4};
    // 		   name	     species teeth age
    
    catalog(snappy);
    label(snappy);
    
    return 0;
}
