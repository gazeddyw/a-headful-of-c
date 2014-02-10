
/*
 * Guard Log
 * A simple program demonstrating system calls using system()
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime (&t));
}

/*
 * Master Control Program utility.
 * Records Guard patrol check-ins.
 */
int main()
{
    char comment[80];
    char cmd[120];
    
    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment,  now());
    // sprintf prints the characters to a string
    
    system(cmd);
    return 0;
}
