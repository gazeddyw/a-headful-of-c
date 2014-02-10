
/*
 * tcx2csv converts a Garmin tcx file into a csv file
 * 
 */

#include <stdio.h>

int main() {
    
    float latitude;
    float longitude;
    char info[80];
    int started = 0;
    FILE *fpr;
    fpr = fopen("activity_168301009.tcx", "r");
    FILE *fpw;
    fpw = fopen("out.txt", "w");
    int colonCount = 0;
    
    while (!feof(fpr)) {
	fprintf(fpw, "%c", fgetc(fpr));
    }
    fclose(fpr);
    fclose(fpw);
    printf("%d", colonCount);
    /*else if (scanf("%f", &longitude) == 1) {
	printf("%16f\n", longitude);
    }
    else {
	printf("Error...\n");
    } */
    
    return 0;
}    
