
/*
 * "encrypt" encrypts a message using XOR encryption
 * 
 */

#include "encrypt.h"

void encrypt(char *message) {
    
    char c;
    while (*message) {
	*message = *message ^ 31;	// XOR encryption
	message++;
    }
    
}
