#ifndef _XOR__H_
#define _XOR__H_

#include <stdio.h>
#include <stdlib.h>

int genKey( int key )
{
    printf("generating key\n" );

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

    return key * randInt;
}

int* xorStrings( char *message, int key, int length)
{
    int ar[length];
    int i = 0;
    for( i = 0; i < length; i++)
    {
        ar[i] = message[i] ^ key;
    }

    return *ar;
}

char* decryptString( int *ar, int key, int length )
{
    char mess[length];
    int i = 0;
    for( i = 0; i < length; i++ )
    {
        message[i] = ar[i] ^ key;
    }

    return *mess;



#endif
