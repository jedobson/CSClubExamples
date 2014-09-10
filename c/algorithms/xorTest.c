#include "xor.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int _ar_size;
    int _ar_i;
    
    scanf( "%d", &_ar_size );
    printf( "%d\n", _ar_size ); 

    char _ar[_ar_size];
    //char *_ar_en;
    //int *key;
    //char *_ar_de;
    
    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++)
    {
        scanf( "%s", &_ar[_ar_i] );
        printf( "%x\n", _ar[_ar_i] );
    }

    _ar_i = 0;
    int *key = genKey( _ar_size );


    char *_ar_en = xorStrings( _ar, key );
    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++ )
    {
        printf( "EN(%x): %c\n", _ar_en[_ar_i], _ar_en[_ar_i] ); 
    }


    _ar_i = 0;

    char *_ar_de = xorStrings( _ar_en, key );

    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++ )
    {
        printf( "DE(%x): %c\n", _ar_de[_ar_i], _ar_de[_ar_i] );
    }

    printf("done");

    free(_ar_en);
    free(_ar_de);
    free(key);

    return 0;
}







