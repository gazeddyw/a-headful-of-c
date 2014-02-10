
/*
 * Price Drinks demonstrates VARIADIC FUNCTIONS
 * Variadic functions can take any number of parameters as arguments
 * 
 */


#include <stdio.h>
#include <stdarg.h>


enum drink {MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE};


double price(enum drink d)
{
    switch (d) {
    case MUDSLIDE:
	return 6.79;
    case FUZZY_NAVEL:
	return 5.31;
    case MONKEY_GLAND:
	return 4.82;
    case ZOMBIE:
	return 5.89;
    }
}


double total(int args, ...)
{
    double total = 0;
    
    va_list ap;  	// Variable arguments are stored in va_list
    va_start(ap, args); // va_list can be controlled with va_start(), va_arg() and va_end()
    
    int i;
    for (i = 0; i < args; i++)
    {
	enum drink d = va_arg(ap, enum drink);	// The data type of every parameter
	total = total + price(d);		// read must be known
    }
    va_end(ap);
    
    return total;
}


int main()
{
    puts("");
    
    printf("Price is: %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Price is: %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Price is: %.2f\n", total(1, ZOMBIE));
    
    puts("");
    return 0;
}
