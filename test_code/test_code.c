
/*
 * Test code to show the use of custom header files previously created
 * 
 */


#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"


int main()
{
    puts("");
    
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %d\n", checksum(s));
    encrypt(s);
    printf("Decrypted back to '%s'\n", s);
    printf("Checksum is %d\n", checksum(s));
    
    puts("");
    
    return 0;
}
