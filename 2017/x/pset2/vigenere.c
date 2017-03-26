#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( int argc, string argv[] )

{
    if (argc != 2)
    {
        printf ("Usage: ./viginere k\n");
        return 1;
    }
    
    
    string key =  argv[1] ; 
    
    for (int counter = 0; counter < strlen(key); counter++)
    {
        if (isalpha(key[counter]))
        {
            continue;
        }
        
        else
        {
            printf ("Usage: ./viginere k\n");
            return 1;
        }
    }
    
    printf("plaintext: "); 
    string data = get_string();
    printf("ciphertext: ");
    int leng = strlen(key);
    int counter2 = 0; 
    int key2 = 0;
    char symbol;
    
    for (int counter = 0; counter < strlen(data); counter++)
    {
        if (isalpha(data[counter]))   
        {
            counter2 = counter2%leng;
            symbol = key[counter2];
            symbol = tolower(symbol);
            key2 = (symbol - 97)%26;
            
            
              if (islower(data[counter]))    
              {
                  int num_a = ((data[counter] - 97) + key2) %26;
                  num_a = num_a + 97;
                  printf("%c", (char) num_a);
              }
            
            
              else
              {
                  int num_b = ((data[counter] - 65) + key2) %26; 
                  num_b = num_b + 65;
                  printf("%c", (char) num_b);
              }
              counter2++;
        }
        
        else
        {
            printf("%c", data[counter]); //symbols
        }
    }
    
    
    printf("\n");
    
} 


