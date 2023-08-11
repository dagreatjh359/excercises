//BOJ 1541
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void clear(int num[], int args)
{
    for (int i = 0; i < args; i++)
    {
        num[i] = 0;
    }
}

int power(int n, int x)
{
    int tmp = n;

    if (x == 0)
    {
        n = 1;
    }
    else
    {
        for (int i = 1; i < x; i++)
        {
            n = n * tmp;
        }
    }
    return n;
}

void extract(char *s, int num[], int *top)
{
    int i = 0;
    int digit = 0;
    int idx = 0;
    int minus_flag = 0;

    while (i <= strlen(s))
    {
        if (i == strlen(s))
        {
            int j = 1;
            while (j <= digit)
            {
                num[idx] = num[idx] + (s[(i - 1) - (digit - 1) + (j - 1)] - '0') * power(10, digit - j);
                j++;
            }
            digit = 0;
            idx++;
        }
        else
        {
            if (s[i] != '-' && s[i] != '+')
            {
                digit++;
            }
            else
            {
                int j = 1;
                while (j <= digit)
                {
                    num[idx] = num[idx] + (s[(i - 1) - (digit - 1) + (j - 1)] - '0') * power(10, digit - j);
                    j++;
                }
                digit = 0;
                idx++;
                
                if(s[i] == '-' && minus_flag==0)
                {
                    num[idx] = 0;
                    idx++;
                    minus_flag = 1;
                }
            }
        }
        i++;
    }

    *top = idx;
}

int main()
{
    char s[100];
    gets(s);

    int num[100];
    int idx;

    clear(num, 100);
    extract(s, num, &idx);

    int result = num[0];
    int i = 1;

    while(num[i] != 0)
    {
        result = result + num[i];
        i++;
    }
    while(i<idx)
    {
        result = result - num[i];
        i++;
    }

    printf("%d", result);

    return 0;
}
