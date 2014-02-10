
/*
 * Program to evaluate card face values
 * Released under the Vegas Public License
 * (c) 2014 The College Blackjack Team
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char card_name[3];
    int count = 0;
    
    puts("Type x to quit");
    
    while ((card_name[0] != 'X') && (card_name[0] != 'x')) {
    
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	int val = 0;
	switch (card_name[0]) {
	    case 'K':
	    case 'Q':
	    case 'J':
		val = 10;
		break;
	    case 'A':
		val = 11;
		break;
	    case 'X':
	    case 'x':
		continue;
	    default:
		val = atoi(card_name);
		if ((val < 1) || (val > 10)) {
		    puts("Please enter a valid card...\n");
		    continue;
		}
	}
    
	printf("The card value is: %i\n", val);
    
	/* Check if the value is 3 to 6 */
	if ((val >= 3) && (val <= 6)) {
	    puts("Count has gone up");
	    count++;
	}
	/* Otherwise check if the card was 10, J, Q, K */
	else if (val == 10) {
	    puts("Count has gone down");
	    count--;
	}
	printf("Current count: %d\n", count);
    }
    return 0;
    
}
