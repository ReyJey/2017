#include <stdio.h>
#include <cs50.h>

int main (void)
{
  int n;
  
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while ((n < 0) || (n > 23));
    
    for (int row = 0; row < n; row++)
        {
            for (int space = 0; space < (n - row - 1); space++)
            {
                printf(" ");
            }
            for (int sharp = 0; sharp < (row + 2); sharp++)
            {
                printf("#");
            }
            printf("\n");
        }
}    