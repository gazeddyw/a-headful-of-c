
/*
 * bad_union.c - An example of a problem with using Unions
 * 
 * The union is set with weight initially, but count is read from it,
 * giving a nonsense result
 */


#include <stdio.h>


typedef union {
    float weight;
    int count;
} cupcake;


int main() {
    
    cupcake order = {2}; // Only the first value has been set (weight)
    printf("Cupcakes quantity: %d\n", order.count); // order.count is not currently stored in the union!
    
    return 0;
}


/*
 * The contents of a union can be kept track of by using an ENUM
 */
