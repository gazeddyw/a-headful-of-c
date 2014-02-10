
/*
 * The Bermuda Rectangle Game
 * 
 * Head First C, Chapter 2
 */

#include <stdio.h>

void go_south_east(int *lat, int *lon) {
    
    *lat = *lat - 1; // Decrease the latitude
    *lon = *lon + 1; // Increase the longitude
    
}


void printCoords(int *latit, int *longit) {
    
    printf("Latitude now: %d\n", *latit);
    printf("Longitude now: %d\n", *longit);
    printf("\n");
    
}


int main() {
    
    int latitude = 32;
    int longitude = -64;
    //int *latptr = &latitude;
    //int *lonptr = &longitude;
    
    go_south_east(&latitude, &longitude); // Call go_south_east with latitude and longitude as arguments
    
    printf("\n");
    printf("Avast! Now at: [%d, %d]\n", latitude, longitude);
    printf("\n");
    
    printCoords(&latitude, &longitude);
    
    return 0;
    
}
    