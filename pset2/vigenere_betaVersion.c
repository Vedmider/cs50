#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
  
    if (argc != 2) {printf("Error\n"); return 1;}  
    
    int k;
    string S = argv[1];
    int m = strlen(S);
    int d;
    for ( d = 0; d < strlen(argv[1]); d++)
    {
    if (argv[1][d] != isalpha(argv[1][d])) {printf("Invalid key word\n"); return 1;}
    }
    
        printf("Please enter text to encrypt  ");
        string s = GetString();
    
    
   
    int n = strlen(s);
    char x;
    
	printf(" ciphertext:");
    
    if (s != NULL)
    {
        int j = 0;
        
        
        for (int i = 0; i < n; i++)
        { 
           
            if (isupper(s[i]) || islower(s[i]))
            {
                j = j % m;          
                k = toupper(S[j])-65;
                j++;
            }
            
            if (isupper(s[i]))
            {
                x = ((s[i]-64) + k)%26 + 64;
                printf("%c", x);
            }
            
            else if (islower(s[i]))
            {
                x = ((s[i] - 96) + k)%26 + 96;
                printf("%c", x);
            }
            
            else {printf("%c", s[i]);}
           
        }    
    
    printf("\n");
    return 0;
    
    }
    


}
