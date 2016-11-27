#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float dollars = 0;
    int coins = 0;
    
    do{
        printf("Enter the amount of changed owed: ");
        dollars = get_float();  
    }
    while(dollars < 0);
    
    int cents = round(dollars * 100);
    
   
        coins += cents / 25;
        cents = cents % 25;

   
        coins += cents / 10;
        cents = cents % 10;
        
  
        coins += cents / 5;
        cents = cents % 5;
    
   
        coins += cents;
    
        
        printf("%i\n", coins);
}
