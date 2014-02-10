
/*
 * 
 * 
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    
    printf("The value of SHRT_MAX is %hi\n", SHRT_MAX);
    printf("The value of SHRT_MIN is %hi\n", SHRT_MIN);
    printf("An short takes %d bytes\n", sizeof(short));
    
    printf("The value of INT_MAX is %d\n", INT_MAX);
    printf("The value of INT_MIN is %d\n", INT_MIN);
    printf("An int takes %d bytes\n", sizeof(int));
    
    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %d bytes\n", sizeof(float));
    
    printf("The value of DBL_MAX is %f\n", DBL_MAX);
    printf("The value of DBL_MIN is %.100f\n", DBL_MIN);
    printf("A double takes %d bytes\n", sizeof(double));
    
    return 0;
}
