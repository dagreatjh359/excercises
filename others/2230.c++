// BOJ 2230 two pointers
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int n[100001]; // 0~1000000000
int res;

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
    int *r = n+1;
    int *l = n;
    res = abs(*(n+N-1) - *l);

    while (l <= r && r < n + N)
    {
        int dif = abs(*r - *l);
        if(dif < M){
            r++;
        }
        else{
            if(dif == M) {
                res = dif;
                break;
            }
            else{
                res = min(dif, res);
                l++;
            }
        }
    }
    cout << res;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    sort(n, n + N);
    solve();
}
