#include <cs50.h>
#include <stdio.h>
#include <string.h>

//
int main(int argc, string argv[])
{
    // iterate over the elements in argv
    for (int i = 0; i < argc; i++)
    {
        //iterate over the characters in i'th element
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            //print the j'th character in the i'th string
            printf("%c\n", argv[i][j]);
        }
    }
}