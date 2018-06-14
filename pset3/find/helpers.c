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
    int lower = 0;
    int upper = n-1;   
       
    // TODO: implement a searching algorithm
    while (lower <= upper)
    {
        if(values[lower] == value || values[upper] == value)
        {return true;}
        
        int m = (lower+upper)/2;
        
        if (values[m] == value)
        {return true;}
                
        else if(values[m] > value)
        {
            upper = m-1;
        }
        
        else
        {
            lower = m+1;
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
