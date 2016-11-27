#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int hash_function(char* key, int size)
{
    int index = 0;


    for (int i = 0; key[i] != '\0'; i++)
    {
         index += toupper(key[i]);
    }


    return index % size;
}

int main()
{
    
    // get hash table size
    printf("Hash table size: ");
    int size = GetInt();

    // get key
    printf("Key: ");
    char* key = GetString();

    // calculate and print index
    printf("The string '%s' is mapped to index %i\n", key, 
    hash_function(key, size));

    return 0;
}
