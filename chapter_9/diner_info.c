
// Diner Info
// Using the getenv() system call

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    puts("");
    
    printf("Diners: %s\n", argv[1]);
    printf("Juice: %s\n", getenv("JUICE"));
    
    puts("");
    return 0;
}
