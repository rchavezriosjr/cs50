#include <stdio.h>



int main (void) 
{
    // int xloc = 1;
    // int yloc = 0;
    // board[xloc][yloc] = 2;
    // int blank_tile = board[i][j];
    // printf("%i\n", blank_tile);
    int board[3][3];
    
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
             int *board_address;
            board_address = &board[i][j];
            printf("%p\n", board_address);
        }
    }
    
   
}
    
