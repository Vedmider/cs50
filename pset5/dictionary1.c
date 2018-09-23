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
/**
 * Returns true if word is in dictionary else false.
 */
 
 typedef struct trie
 {
    bool word;
    struct trie* children[27];
 } trie;
 
 struct trie* firstpointer ;
 
 int wordsNum = 0;
 
//
 
bool check(const char* word)
{
    // TODO
    int i = 0;
    int index;
    trie* cursornode = firstpointer;
    
    while(word[i] != '\0')
    {
        
        index = tolower(word[i]) - 97;
        if(word[i] == '\'')
        { index = 26; }
        
        if(cursornode -> children[index] != NULL)
        {
            cursornode = cursornode -> children[index];
        }
        else
        { return false; }
    }
    
    if(word[i] == '\0')
    {
        if(cursornode -> word == true)
        { return true; }
        else
        { return false; }
    }
    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    //1. we will open dictionary file 
    FILE* f = fopen(dictionary, "r");
    if(f == NULL)
    {
        if(ferror(f))
        {printf("file read error.\n");}
        else
        {printf("couldn't open the file.\n");}
        return false;
    }
   
    firstpointer = (trie*)malloc(sizeof(trie));
    // cursor pointer
    trie* pointer = firstpointer;
    unsigned int index;
    
    //start loading the dictionary into memory
    for(int c = fgetc(f); c != EOF; c = fgetc(f))
    {
        
        if(isalpha(c))
        {
            
            index = c - 97;
            if(pointer->children[index] == NULL)
            {pointer->children[index] = malloc(sizeof(trie));}
            
            pointer = pointer->children[index];                
        
        }
        else if(c == '\'')
        {
            index = 26;
            if(pointer->children[index] == NULL)
            {pointer->children[index] = malloc(sizeof(trie));}
            else
            pointer = pointer->children[index];
        
        }
        else if(c == '\n')
        {
            pointer->word = true;
            pointer = firstpointer;
            wordsNum++;
        }
    }
    
    fclose(f);
    return true; 
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return wordsNum;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
void unloadDict(trie* firstpointer)
{
    for(int i = 0; i < 27; i++)
    {
        if(firstpointer->children[i] != NULL)
        {unloadDict(firstpointer->children[i]);}
    }
    
    free(firstpointer);
    return;
}

bool unload(void)
{
    // TODO
    unloadDict(firstpointer);

    return true;
}
