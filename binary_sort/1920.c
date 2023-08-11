#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int binarySearch(int *p, int start, int end, int tgt)
{
    if (end < start)
        return 0;

    int mid = (start + end) / 2;

    if (*(p + mid) == tgt)
        return 1;
    else if (*(p + mid) > tgt)
        return binarySearch(p, start, mid - 1, tgt);
    else
        return binarySearch(p, mid + 1, end, tgt);
}

int main()
{
    int N, M;
    int arrN[100000];
    int arrM[100000];
    int i_arrN, i_arrM;

    scanf("%d", &N);
    for (i_arrN = 0; i_arrN < N; i_arrN++)
    {
        scanf("%d", arrN + i_arrN);
    }

    scanf("%d", &M);
    for (i_arrM = 0; i_arrM < M; i_arrM++)
    {
        scanf("%d", arrM + i_arrM);
    }

    qsort(arrN, N, sizeof(int), cmp);

    for (i_arrM = 0; i_arrM < M; i_arrM++)
    {
        printf("%d ", binarySearch(arrN, 0, N, *(arrM + i_arrM)));
    }

    return 0;
}
