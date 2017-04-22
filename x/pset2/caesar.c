#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( int argc, string argv[] )

{
    if (argc != 2)
    {
        printf ("Usage: ./caesar k\n");
        return 1;
    }
    
    
    int key = atoi( argv[1] ); //converting variable
    printf("plaintext: "); 
    string data = get_string();
    
    printf("ciphertext: ");
    
    for (int counter = 0; counter < strlen(data); counter++)
    {
        if (isalpha(data[counter]))   
        {
            if (islower(data[counter]))    //check lowercase
            {
                int num_a = ((data[counter] - 97) + key) %26;
                num_a = num_a + 97;
                printf("%c", (char) num_a);
            }
            
            
            else
            {
                int num_b = ((data[counter] - 65) + key) %26; //check uppercase
                num_b = num_b + 65;
                printf("%c", (char) num_b);
            }
        }
        
        else
        {
            printf("%c", data[counter]); //symbols
        }
    }
    
    
    printf("\n");
    
} 


