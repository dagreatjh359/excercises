// BOJ 2003 two pointers
#include <iostream>

using namespace std;

int N, M;
int n[100001];
int res = 0;

void input()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }
}

void solve()
{
    int* l = n;
    int* r = n+1;
    int sum = *l;

    while(l<=r && r<=n+N)
    {
        if(sum == M)
        {
            res++;
        }
        if(sum < M)
        {
            sum += *r;
            r++;
            continue;
        }
        if(sum >= M)
        {
            sum -= *l;
            l++;
            continue;
        }
    }
    cout << res;
}

int main()
{
    input();
    solve();
}
