
/*
 * Send Dear Johns... Featuring an ARRAY OF FUNCTION POINTERS
 * Function pointers are designed to make code SCALABLE by
 * making it shorter and easier to extend.
 * 
 */


#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE, LAW_SUIT};

typedef struct {
    char *name;
    enum response_type type;
} response;


void dump(response r)
{
    printf("\nDear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again.");
}


void second_chance(response r)
{
    printf("\nDear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}


void marriage(response r)
{
    printf("\nDear %s,\n", r.name);
    puts("Congratulations! Your last date has");
    puts("contacted us with a proposal of marriage.");
}


void law_suit(response r)
{
    printf("\nDear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to say");
    puts("that they will be filing a law suit against you.");
}


// This is an array of function pointers, called in main
// The array names are in line with the enum above
void (*replies[])(response) = {dump, second_chance, marriage, law_suit};

int main()
{
    puts("");
    
    response r[] = {
	{"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", LAW_SUIT}, {"William", MARRIAGE}
    };
    
    int i;
    for (i = 0; i < 4; i++)
    { // This is a function | pass it the response data r[i] 
	(replies[r[i].type]) (r[i]);
    }
    
    puts("");
    return 0;
}
    