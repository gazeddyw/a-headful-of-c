
/*
 * three_card_monte
 * Guess where the Queen is!
 * Chapter 2, Head First C
 * 
 */

#include <stdio.h>

int main() {
    
    printf("\n");
    
    // The *cards variable can't modify the string!
    // char *cards = "JQK"; // This fails at runtime because STRING LITERALS CAN NEVER BE UPDATED
    
    const char *cardsptr = "JQK";
    char cards[] = "JQK"; // This makes a COPY of "JQK" and stores it in the cards array
    char a_card = cards[2];
    puts(cards);
    cards[2] = cards[1];
    puts(cards);
    cards[1] = cards[0];
    puts(cards);
    cards[0] = cards[2];
    puts(cards);
    cards[2] = cards[1];
    puts(cards);
    cards[1] = a_card;
    puts(cards);
    puts(cardsptr);
    
    printf("\n");
    
    return 0;
    
}
