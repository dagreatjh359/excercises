// BOJ 2805
#include <iostream>

using namespace std;

int N, M;
int tree[1000001];
int low = 0;
int high = 0;
int mid;
int result = 0;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
        if (high < tree[i])
        {
            high = tree[i];
        }
    }

    while(low <= high)
    {
        mid = (low+high)/2;
        long long sum = 0;

        for(int i=0;i<N;i++)
        {
            if(tree[i] < mid) continue;
            sum += tree[i] - mid;
        }
        if(sum >= M) //sum is at least bigger than M
        {
            result = mid;  // that is why we should keep our mid in the result
                           // we are not finding the exact result(=M) we are finding "at least bigger than" M
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        // low = mid+1, high = mid-1 -> when mid is not the number that is considered then we should exclude the mid number
        // and try other adjacent numbers
    }

    cout << result;

    return 0;
}
