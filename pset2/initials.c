#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// declare initialize function
void initialize(string name);

// create main function
int main(void)
{
    // Prompt the user for their name and collect it with get_string
    string name = get_string();
    
    // if name is not null, run the initialize function on name
    if (name != NULL)
    {
        initialize(name);
    }
    
    return 0;
}

// create initialize function
void initialize(string name)
{
    // initialize "start" variable to zero
    int start = 0;
    
    // Skip over any initial spaces in string
    while (name[start] == ' ')
    {
        start++;
    }
    
    // Print first non-space character
    printf("%c", toupper(name[start]));
    
    // Iterate over the rest of the string
    for (int i = start + 1, length = strlen(name); i < length; i++)
    {
        // if previous character was a space and current character is not a space
        // print current character
        if (name[i - 1] == ' ' && name[i] != ' ')
        {
            printf("%c", toupper(name[i]));
        }
    }
    
    printf("\n");
}