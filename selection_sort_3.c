#include <stdio.h>

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);

    int num[10000];

    for(int i = 0; i<N;i++){
        scanf("%d",&num[i]);
    }

    int max, tmp, ch = 0;

    for(int i=N-1;i>0;i--)
    {
        max = num[i];
        int idx = i;

        for(int j=0;j<=i;j++)
        {
            if(max < num[j])
            {
                max = num[j];
                idx = j;
            }
        }
        if(max != num[i])
        {
            ch++;
            tmp = num[idx];
            num[idx] = num[i];
            num[i] = tmp;
            if(ch == k)
            {
                for(int n=0;n<N;n++)
                {
                    printf("%d ",num[n]);
                }
            }
        }
    }
    if(k>ch)
        printf("-1\n");

    return 0;
}