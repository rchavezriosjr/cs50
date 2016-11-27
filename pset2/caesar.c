#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Get a cipher key from the user
int main (int argc, string argv[])
{
    // If there are not exactly two command line arguments, return 1
    if (argc != 2)
    {
        printf("Invalid keyword. Please enter a keyword that contains only letters of the alphabet.\n");
        return 1;
    }
    
    // Convert the key to an integer and store it in variable k
    int k = atoi(argv[1]);
    
    // Prompt the user for a plaintext string
    string message;
    do
    {
        printf("plaintext: ");
        message = get_string();
    }
    while (message == NULL);
    
    // Iterate over each character in the string
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // Check to see if the character is alphabetical
        if (isalpha(message[i]))
        {
            // Check to see if the character is uppercase
            if (isupper(message[i]))
            {
                // Convert ascii value to alphabetical index value
                // Add key
                // Convert back to ascii
                int upperAlphaIndex = message[i] - 65;
                message[i] = (upperAlphaIndex + k) % 26 + 65;
                
            }
            // Otherwise, character is lowercase
            else
            {
                // Convert ascii value to alphabetical index value
                // Add key
                // Convert back to ascii
                int lowerAlphaIndex = message[i] - 97;
                message[i] = (lowerAlphaIndex + k) % 26 + 97;
            }
        }
        // // Character is not alphabetical, print the character as is
        // else
        // {
        //     printf("%c", p[i]);
        // }
    }
    
    // Print a newline, return 0
    printf("ciphertext: %s\n", message);
    return 0;
}

