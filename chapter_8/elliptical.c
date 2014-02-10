
/*
 * Test code for the Elliptical trainer
 * 
 */


#include <stdio.h>
#include <hfcal.h>


int main()
{
    puts("");
    
    // The user weighs 115.2 lbs, done 11.3 miles on the elliptical
    // and 0.79 is the coefficient for the machine
    display_calories(115.2, 11.3, 0.79);
    
    puts("");
    return 0;
}
    