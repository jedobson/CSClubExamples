#include <stdio.h>
#include <stdlib.h>
#include "primality.h"

int main()
{
    int p;
    int bol;

    printf( "enter number: " );
    scanf( "%d", &p );
    
    if( !( bol = primality( p ) ) )
    {
        printf("Number is prime\n");
    }
    else
    {
        printf("Number is not prime\n");
    }
    
}


