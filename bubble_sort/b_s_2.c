//BOJ 23968
#include <stdio.h>

int main()
{
    int N, k, tmp, cnt = 0;
    scanf("%d %d", &N, &k);

    int num[10000];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[j] > num[j + 1])
            {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
                cnt++;
                if (k == cnt)
                {
                    printf("%d %d", num[j], num[j + 1]);
                    break;
                }
            }
        }
    }
    if (cnt < k)
        printf("-1");

    return 0;
}