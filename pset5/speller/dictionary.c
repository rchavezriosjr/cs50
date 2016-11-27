/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Create node struct
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// hashtable buckets constant
#define NUM_BUCKETS 10000

//global dictionary hashtable
node* hashtable[NUM_BUCKETS];

// global dictionary size
unsigned int hashtable_size = 0;

// Create hash function
int hash_func(const char* key)
{
    int index = 0;

    for (int i = 0; key[i] != '\0'; i++)
    {
         index += toupper(key[i]);
    }


    return index % NUM_BUCKETS;
}




/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // find hash value of word, go to appropriate bucket in hashtable
    node* bucket = hashtable[hash_func(word)];
    
    for(node* entry = bucket; entry != NULL; entry = entry->next)
    {
        if (strcasecmp(entry->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}
/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
   // open dictionary
   FILE* dictionary_file = fopen(dictionary, "r");
   // check to make sure dictionary opened
   if (dictionary_file == NULL)
   {
       return false;
   }
   
   // loop through words in dictionary
   while(true)
   {
       // create node to store current word
       node* entry = malloc(sizeof(node));
       if (entry == NULL)
       {
           unload();
           fclose(dictionary_file);
           return false;
       }
       
       // attempt to read a word from dictionary and store in entry node
       if (fscanf(dictionary_file, "%45s", entry->word) != 1)
       {
           free(entry);
           break;
       }
       
       // hash word
       unsigned int hash = hash_func(entry->word);
       
       // insert word into hashtable
       entry->next = hashtable[hash];
       hashtable[hash] = entry;
       
       // increment hashtable_size
       hashtable_size++;
   }
   
   // fail in error reading dictionary_file
   if (ferror(dictionary_file))
   {
       unload();
       fclose(dictionary_file);
       return false;
   }
   
   // otherwise, close dictionary, return true
   fclose(dictionary_file);
   return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return hashtable_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        node* entry = hashtable[i];
        
        while (entry != NULL)
        {
            node* next = entry->next;
            free(entry);
            entry = next;
        }
    }
    return true;
}
