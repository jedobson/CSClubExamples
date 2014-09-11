#ifndef _PRIMALITY__H_
#define _PRIMALITY__H_

int primality( int randVal )
{
    int r;
    int fact = factorial( randVal - 1);
    
    if( ((fact + 1 ) % randVal) == 0)
    {
        r = 0;
    }
    else
    {
        r = 1;
    }

    return r;
}

int factorial( int fact )
{
    

    if( fact <= 1 )
    {
        return fact;
    }
    else
    {
        return fact * factorial(fact-1);
    }
    

}

#endif
