#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    printf("Type your name, please\n");
    string s = GetString(); 
    
    int t = 1;
    int n = strlen(s);
    
    if (s != NULL)
    {
        for (int i = 0; i < n; i++)
        {
           if (islower(s[i]) || isupper(s[i]))
           {
               if (t == 1) {printf("%c", toupper(s[i])); t *= -1;}
           }
           
           else if (s[i] != islower(s[i]) || s[i] != isupper(s[i]))
           {
               if (t == -1) {t *= -1;}
           }
        }
     }
  printf("\n");
}
