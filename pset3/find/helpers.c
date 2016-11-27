/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    else
    {
        int first, middle, last;
        
        first = 0;
        last = n - 1;
        
        while (last >= first) 
        {
            middle = (first + last)/2;
            if (values[middle] == value)
            {
                return true;
            }
            else if (values[middle] > value)
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
        }
        return false;
    }
   
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = values[i];
       j = i-1;
 
       /* Move elements of values[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && values[j] > key)
       {
           values[j+1] = values[j];
           j = j-1;
       }
       values[j+1] = key;
   }
}
