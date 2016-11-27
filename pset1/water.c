#include <stdio.h>
#include <cs50.h>


int main(void){
    int minutes;
    
    // promp the user for a "minutes" integer greater than 0
    do {
        printf("Minutes: ");
        minutes = get_int();
    }
    while (minutes < 0);
    int bottles = minutes * 12;
    printf("Bottles: %i\n", bottles);
}