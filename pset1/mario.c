#include <stdio.h>
#include <cs50.h>

int main(void){
    int height = 0;
    
    // prompt user for a height integer greater than 0 and less than 24
    do {
        printf("Enter a non-negative integer less than 24: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    for (int row = 1; row <= height; row++){
        
        // declare spaces variable
        int spaces = height - row;
        
        //print number of spaces
        for (int j = 0; j < spaces; j++){
            printf(" ");
        }
        
        // print left pyramid hashes
        for (int j = 0; j < row; j++){
            printf("#");
        }
        
        // print two spaces
        for (int j = 0; j < 2; j++){
            printf(" ");
        }
        
        // print right pyramid
        for (int j = 0; j < row; j++){
            printf("#");
        }
        
        // print newline
        printf("\n");
        
    }
    
}