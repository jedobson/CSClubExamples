#include "xor.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int _ar_size;
    int _ar_i;
    
    scanf( "%d", &_ar_size );

    _ar_size += 1;
    
    char _ar[_ar_size];
    int _ar_en[_ar_size];
    char _ar_de[_ar_size];
    
    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++)
    {
        scanf( "%s", &_ar[_ar_i] );
    }

    _ar_i = 0;

    int key = genKey(_ar_size);

    printf("%d\n", key);

    *_ar_en = xorStrings( _ar, key, _ar_size);

    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++)
    {
        printf( "%s", &_ar_en[_ar_i] );
    }

    printf("\n");

    _ar_i = 0;

    *_ar_de = decryptString( _ar_en, key, _ar_size);
    
    for( _ar_i = 0; _ar_i < _ar_size; _ar_i++ )
    {
        printf( "%s", &_ar_de[_ar_i] );
    }

    printf("done");

    return 0;
}







