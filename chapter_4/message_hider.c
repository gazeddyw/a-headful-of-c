
/*
 * "message_hider" takes in a message from the cmd line
 * and prints an encrypted version to std out
 * 
 */

#include <stdio.h>
#include "encrypt.h"

int main() {
    
    char msg[80];
    
    puts("");
    
    while (fgets(msg, 80, stdin)) {
	encrypt(msg);
	printf("%s\n", msg);
    }
    
    return 0;
}
