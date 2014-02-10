
// My Exec Program
// Calls diner_info program

#include <stdio.h>
#include <unistd.h>     // Needed for the exec() functions
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Each variable in the ENVIRONMENT is NAME=value
    char *my_env[] = {"JUICE=peach and apple", NULL};   // The last item in the array MUST be NULL
    
    if (execle("diner_info", "diner_info", "4", NULL, my_env) == -1) {   // The last item in the sys call MUST be NULL
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }
        
    return 0;
}
