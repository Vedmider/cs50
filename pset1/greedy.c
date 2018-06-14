#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{

   float sum;
   int coins_sum;
   int odd_coins = 0;
   
   do 
   {
       printf("Enter correct cash value: ");
       sum = GetFloat();
   }
   while (sum < 0 );
   
   coins_sum = round(sum*100);
   
   while (coins_sum > 0)
   {
       if ((coins_sum - 25) >= 0)
       {
         coins_sum = coins_sum - 25; odd_coins++;
       }
       else if ((coins_sum - 10) >= 0)
       {
         coins_sum = coins_sum - 10; odd_coins++;
       }
       else if ((coins_sum - 5) >= 0)
       {
         coins_sum = coins_sum - 5; odd_coins++;
       }
       else if (coins_sum >= 0)
       {
         coins_sum--; odd_coins++;
       }
              
   }
   
   printf("Your number of change is: %d\n", odd_coins);
   
   return 0;
   
   
}
