#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
   int i = 2;
   FILE *fp;
   fp = fopen("RamTrash.txt", "wb");
   do
   {
    fprintf(fp,"%s\n", argv[i]);
    i++;
    }
    while(i != EOF);
    fclose(fp);
}
