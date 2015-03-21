#ifndef _KMP___ALG__H_
#define _KMP___ALG__H_

int kmp( char s[], char w[] )
{
    int m = 0;
    int i = 0;
    int t[];

    while( m + i < strlen( s ) )
    {
        if( w[i] == s[m+i] )
        {
            if( i == strlen( w ) - 1)
            {
                return m;
            }
            i++;
        }
        else
        {
            if( t[i] > -1 )
            {
                m = m + ( i - t[i] );
                i = t[i];
            }
            else
            {
                i = 0;
                m++;
            }

        }
    }
    return strlen(s);
}

//TODO write the kmp_table
        
#endif
