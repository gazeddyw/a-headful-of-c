
/*
 * enum_test.c shows how an enum can be used to keep track of what is 
 * stored in a union at any one time
 * 
 */


#include <stdio.h>


typedef enum {
    COUNT, POUNDS, PINTS
} unit_of_measure;


typedef union {
    short count;
    float weight;
    float volume;
} quantity;


typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;


static void display(fruit_order first);


int main() {
    
    puts("");
    
    fruit_order apples = {"apples", "England", .amount.count = 144, COUNT};
    
    fruit_order strawberries = {"strawberries", "Spain", .amount.weight = 17.6, POUNDS};
    
    fruit_order oj = {"orange juice", "U.S.A.", .amount.volume = 10.5, PINTS};
    
    display(apples);
    display(strawberries);
    display(oj);
    
    puts("");
    
    return 0;
}


static void display (fruit_order order) {
    
    printf("This order contains ");
    
    if (order.units == PINTS)
	printf("%2.2f pints of %s\n", order.amount.volume, order.name);
    
    else if (order.units == POUNDS)
	printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
    
    else
	printf("%d %s\n", order.amount.count, order.name);
}
