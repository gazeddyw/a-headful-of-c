
/*
 * 
 * 
 */


#include <stdio.h>


enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

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


int main()
{
    puts("");
    
    response r[] = {
	{"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
    };
    
    int i;
    for (i = 0; i < 4; i++)
    {
	switch (r[i].type) {
	case (DUMP):
	    dump(r[i]);
	    break;
	case (SECOND_CHANCE):
	    second_chance(r[i]);
	    break;
	default:
	    marriage(r[i]);
	}
    }
    
    puts("");
    return 0;
}
    