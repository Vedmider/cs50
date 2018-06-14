/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
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
    
   if (n < 1) {return false;}
   
       
    // TODO: implement a searching algorithm
    for (int i = 0; i < n; i++)
    {
        if(values[i] == value)
        {
           return true;
        }
    }
    
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n - 1; i++)
    {
        int m = 0;
        
        for (int b = 0; b < n -1; b++)
        {
            if (values[b] > values[b+1])
            {
                int c = values[b];
                values[b] = values[b+1];
                values[b+1] = c;
                m++;
            }    
        }
    
        if(m < 1)
        {break;}
    }
    return;
}
