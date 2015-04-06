#include<stdio.h>
#include<string.h>


int main()
{
    int ops = 0;
    int t = 0;
    int n = 0;
    int i = 0;
    scanf("%d",&n);
    char p[n][1000];
    for(i =0; i<n; i++)
    {
        scanf("%s",p[i]);
    }
    for(i=0; i<n; i++)
    {
        int x = strlen(p[i]);
        int len = x-1;
        if(x%2)
        {
            len = x/2;
            for(len; len<x; len++)
            {
                p[i][len] = p[i][len+1];
            }
            len -= 2;
        }

        for(t; t < x/2; t++)
        {
        
            while(p[i][t] != p[i][len])
            {
                p[i][len] -= 1;
                ops++;
            }
            len--;
        }

        printf("%d\n", ops);
        ops = 0;
    }


}

