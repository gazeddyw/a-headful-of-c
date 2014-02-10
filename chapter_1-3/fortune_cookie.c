
/*
 * Fortune Cookie :-
 * 
 * Pass a string to a function using a char[] 
 * 
 * Head First C, Chapter 2
 */

#include <stdio.h>

void fortune_cookie(char msg[]) {
    
    printf("Message reads: %s\n", msg);
    printf("msg is at: %p\n", &msg);
    printf("msg occupies %d bytes\n", sizeof(msg));
    printf("char occupies %d byte\n", sizeof(char));
    
}

int main() {
    
    printf("\n");
    
    char quote[] = "Cookies make you fat! FAT!!";
    fortune_cookie(quote);
    
    printf("quote occupies %d bytes\n", sizeof(quote));
    printf("quote pointer occupies %d bytes\n", sizeof(&quote));
    printf("quote is at: %p\n", &quote);
    
    printf("\n");
    
    return 0;
}
