#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)

{
    float f;
    do
    {
        printf("O hai! How much change is owed? ");
        f = GetFloat();
    }
    while (f < 0);
    
    int dolar = roundf(f * 100);
    int counter = 0;
    
    while (dolar >= 25)
    {
        dolar = dolar - 25; 
        counter++;
    }
    
    while (dolar >= 10)
    {
        dolar = dolar - 10; 
        counter++;
    }
    
    while (dolar >= 5)
    {
        dolar = dolar - 5; 
        counter++;
    }
    
    while (dolar >= 1)
    {
        dolar = dolar - 1; 
        counter++;
    }
    
    printf("%i\n",counter);
}