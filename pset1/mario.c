#include <stdio.h>
#include <cs50.h>

int main (void)
{
  
  int height;
   
   do
   {
      printf("Please specify the height of the pyramid: ");
      height = GetInt();
    }
	while (height  < 0 || height > 23);
		
	int i;
	for (i = 1; i <= height; i++)
	{
	   
	    int j;
		for (j = height - i; j > 0; j--)
		{
			printf(" ");
		}
		
		int k;
		for (k = 0; k < 1 + i; k++)
		{
			printf("#");
		}
	
	printf("\n");
	
	}	
}
