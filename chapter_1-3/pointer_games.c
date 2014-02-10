
/*
 * Program to experiment with C pointers
 * 
 * (c) Gareth Williams, 2013
 */

#include <stdio.h>


int globalVar = 5;
int globalVar2 = 6;
int globalVar3 = 7;

int main(int argc, char *argv[]) {
    
    int localVar = 2;
    int i = 0;
    char user_args[argc];
    
    printf("\n");
    printf("Program running is: %s\n", argv[0]);
    printf("argc is %d\n\n", argc);
	
    for ( i = 1; i < argc; i++ ) {
	puts( argv[i] );
	
	if (*argv[i] == 'g') {
	    printf("Global variable is at: %p\n", &globalVar);
	}
	else if (*argv[i] == 'l') {
	    printf("Local variable is at: %p\n", &localVar);
	}
	else {
	    printf("Please enter a valid argument...\n");
	}
    }
    
    
    
    //printf("Global variable 1 is stored at: %p\n", &globalVar);
    //printf("Global variable 2 is stored at: %p\n", &globalVar2);
    //printf("Global variable 3 is stored at: %p\n", &globalVar3);
    //printf("Local variable is stored at: \t%p\n", &localVar);
    
    printf("\n");
    return 0;
}
