#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int keywordIndexer (int letter);


int main (int argc, string argv[])
{   
    // Get a cipher key from the user
    // If there are not exactly two command line arguments...
    if (argc != 2)
    {
        // ...request a valid keyword
        printf("Invalid keyword. Please enter a keyword that contains only letters of the alphabet.\n");
        return 1;
    }
    
    // Store argv[1] value in variable "keyword" and calculate its length
    char * keyword = argv[1];
    int keyword_length = strlen(keyword);
    // Iterate over the keyword, checking to make sure each chacter is a 
    // letter of the alphabet
    for (int i = 0; i < keyword_length; i++)
    {
        if (isalpha(keyword[i]) == false)
        {
            printf("Keyword must only contain letters A-Z or a-z\n");
            return 1;
        }
    }
    
    // Prompt the user for a message to encrypt
    string message;
    do
    {
        printf("plaintext: ");
        message = get_string();
    }
    while(message == NULL);
    
    // Encrypt the message, replacing message[i] with rotated character. 
    // Do not encrypt non-alphabetical characters.
    // message_letter_count variable is incremented only when current message character is letter of the alphabet.
    int message_letter_count = 0;
    for(int i = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]))
        {
            // Calculate key for current letter using custom keywordIndexer method
            int key = keywordIndexer(keyword[message_letter_count % keyword_length]);
           
            // Check to see if message letter is uppercase 
            if (isupper(message[i]))
            {
                // Replace current letter with encrypted letter
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            }
            // If not, it is lowercase
            else
            {
                // Replace current letter with encrypted letter
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
            // Increment message_letter_count
            message_letter_count++;
        }
    }
    
    // Print encrypted message
    printf("ciphertext: %s\n", message);
    return 0;
    
}

// Define method to convert ASCII value to alphabet index (0 - 25)
int keywordIndexer(int letter)
{
   // Check to see if the character is uppercase
    if (isupper(letter))
    {
        // Convert ascii value to alphabetical index value
        int alphabet_index = letter - 'A';
        return alphabet_index;
    }
    // Otherwise, character is lowercase
    else
    {
        // Convert ascii value to alphabetical index value
        int alphabet_index = letter - 'a';
        return alphabet_index;
    }
}