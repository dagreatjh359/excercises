#include <stdio.h>

int main()
{

    int num[10] = {1, 7, 5, 8, 2, 6, 4, 3, 10, 9};
    int min, tmp, idx; //no initiaion on min and idx, which will be implemented on other variables

    for (int i = 0; i < 9; i++)
    {
        min = num[i];
        for (int j = i + 1; j < 10; j++)
        {
            if (min > num[j])
            {
                min = num[j]; // this part affects the idx
                idx = j;
            }
        }

        if (min != num[i]) //if min actually was a minimum, there will be no change in idx
        {
            tmp = num[i];
            num[i] = num[idx];
            num[idx] = tmp;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}