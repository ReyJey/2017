#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)

{
string n = get_string();
int len = strlen(n);
printf ("%c", toupper(n[0]));

for (int counter = 0; counter < len; counter++)
    {
        if (n[counter] == ' ')
        {
            printf ("%c", toupper(n[counter+1]));
        }
    }
    printf ("\n");
    
}