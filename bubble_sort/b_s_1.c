/*bubble sort
비교하는 집합의 개수가 N, N-1, N-2, N-3, ...,2로 줄어든다.
이를 통해 비교횟수는 N(N+1)/2로 알 수 있는데 이는 시간 복잡도가 O(N^2)이다

버블 정렬은 선택 정렬보다 속도가 느리다.
선택 정렬은 비교 후 두 수의 위치를 바꾸지 않는 반면, 버블 정렬은 비교 후 바꾼다.(tmp 사용)
*/

#include <stdio.h>

int main()
{
    int num[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int tmp;

    for(int i = 9; i > 0; i--)
    {
        for(int j = 0; j<i; j++)
        {
            if(num[j] > num[j+1])
            {
                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i< 10; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}