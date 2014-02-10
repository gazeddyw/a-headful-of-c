
/*
 * categorise.c reads the latitude, longitude 
 * and info from a csv file, then writes the data
 * to three other csv files
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char line[80];
    
    if (argc != 6) {
	fprintf(stderr, "5 arguments are required\n");
	return 1;
    }
    
    FILE *in;
    FILE *file1;
    FILE *file2;
    FILE *file3;
    
    // Check to ensure files can be opened
    if (!(in = fopen("spooky.csv", "r"))) {
	fprintf(stderr, "Unable to open input file\n");
	return 1;
    }
    else if (!(file1 = fopen(argv[2], "w"))) {
	fprintf(stderr, "Unable to open first output file\n");
	return 1;
    }
    else if (!(file2 = fopen(argv[4], "w"))) {
	fprintf(stderr, "Unable to open second output file\n");
	return 1;
    }
    else if (!(file3 = fopen(argv[5], "w"))) {
	fprintf(stderr, "Unable to open third output file\n");
	return 1;
    }
    
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
	
	if (strstr(line, argv[1]))
	    fprintf(file1, "%s\n", line);
	else if (strstr(line, argv[3]))
	    fprintf(file2, "%s\n", line);
	else
	    fprintf(file3, "%s\n", line);
	
    }
    
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    return 0;
}

