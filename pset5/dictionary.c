/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include <string.h>
/**
 * Returns true if word is in dictionary else false.
 */ 
 
 typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* root;
 
 int getIndex(const char c)
{
    if (c == '\'') 
    {
        return 26;    
    }
    else 
    {
        return tolower(c) % 'a';
    }
}

int total_nodes; 
 
 
 
 
 
bool check(const char* word)
{
    // Set cursor to root
    node* cursor = root;
    
    // for each letter in input word
    for (int i = 0; word[i] != '\0'; i++) 
    {
        // Find the index of the letter
        int index = getIndex(word[i]);
        
        // got to corresponding element in children
        if (cursor->children[index] == NULL) 
        {
            // if NULL word is mispelled
            return false;
        }
        
        // if not NULL, move to next letter
        cursor = cursor->children[index];
    }
    
    // once at end of input word, check if is_word is true
    return cursor->is_word;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Create space for root
    root = (node*)malloc(sizeof(node));
	for (int i = 0; i < 27; i++)
    {
    root->children[i] = NULL;
    }
    memset(root, 0, sizeof(node));
    // Initialize number of nodes
     total_nodes = 0;
    
    // Read dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }
    
    // Set cursor to root
    node* cursor = root;
    
    // Read each character in dictionary
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // Check if newline
        if (c == '\n') 
        {
            // mark as word
            cursor->is_word = true;
            
            // Increment number of nodes
            total_nodes++;
            
            // reset cursor to root to traverse trie again
            cursor = root;
        }
        else 
        {
            // Find the index of the letter
            int index = getIndex(c);
            
            // Check if node exists for letter
            if (cursor->children[index] == NULL) 
            {
                // Create new node
                cursor->children[index] = (node*)malloc(sizeof(node));
                memset(cursor->children[index], 0, sizeof(node));
                
            }

            // Move to next node
            cursor = cursor->children[index];
            
        }
    }
    
    // Close dictionary
    fclose(fp);
    
    return true;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return total_nodes;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unloadDict(node* root )
{
    for(int i = 0; i < 27; i++)
    {
        if(root->children[i] != NULL)
        {unloadDict(root->children[i]);}
    }
    
    free(root);
    return true;
}

bool unload(void)
{
    // TODO
   
    return unloadDict(root);

    
}
