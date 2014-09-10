#ifndef _XOR__H_
#define _XOR__H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/* * * * * * * * * * * * * * * * *
 * Basic XOR Cypher written in C *
 * * * * Justin Dobson * * * * * *
 * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * */


/* Generates key to be used in the encryption/decryption *
 * Process, takes in int(usually number of characters to *
 * be encyrpted) and value from /dev/random *************/
int genKey( int key )
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
            return -1;
        }
        randLength += result;

    }
    close( randData );
    int ar_key = key * randInt;

    return ar_key;
}

/* Decrypt/encrypt fuunctions, take string *
 * and XOR with key for both * * * * * * * */

char* xorStrings( char *message, int key )
{
    printf("encrypting string\n");
    int i = 0;
    for( i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] ^ key;
    }
    return message;
}

char* decryptStrings( char *mess, int key )
{
    printf("decrypting string\n");
    int j = 0;
    for(j = 0; mess[j] != '\0'; j++)
    {
        mess[j] = mess[j] ^ key;
    }

    return mess;
}

#endif
