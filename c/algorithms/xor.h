#ifndef _XOR__H_
#define _XOR__H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int* genKey( int key )
{
    printf( "generating key\n" );

    int randData = open("/dev/random", O_RDONLY );
    int randInt;
    
    size_t randLength = 0;

    while( randLength < sizeof( randInt ) )
    {
        ssize_t result = read( randData , ((char *)&randInt) + randLength, (sizeof( randInt)) - randLength );
        if( result < 0 )
        {
            printf( "error reading /dev/random\n");
            return 1;
        }
        randLength += result;

    }
    close( randData );
  
    int ar_key[key];
    int i = 0;
    for( i = 0; i < key; i++ )
    {
        ar_key[i] = key;
    }

    printf("ar_key: %d\n", ar_key[0] );

    return ar_key;
}

char* xorStrings( char *message, int *key, int length)
{
    char ar[length];
    int i = 0;
    for( i = 0; i < length; i++)
    {
        ar[i] = message[i] ^ key[i];
        printf( "ar[%d]: %x\n", i, ar[i] );
        printf( "key: %d\n", key[i] );
    }

    return ar;
}

char* decryptString( char *ar, int *key, int length )
{
    printf("%x\n", ar[0]);
    char mess[length];
    int i = 0;
    for( i = 0; i < length; i++ )
    {
        mess[i] = ar[i] ^ key[i];
        printf( "DE_ar[0]: %x\n", ar[i] );
        printf( "key: %d\n", key[i] );
    }

    return mess;
}


#endif
