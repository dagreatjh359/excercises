// BOJ 1697
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
bool visited[100001];
queue<pair<int, int>> q;
int N, K;

void input()
{
    cin >> N >> K;
    fill_n(visited, 100001, false);
    q.push(make_pair(N, 0));
    visited[N] = true;
}

void solution()
{
    if (N == K)
    {
        cout << 0;
        return;
    }

    while (!q.empty())
    {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        int search[3] = {2 * curr, curr + 1, curr - 1}; // search method -> *2, +1, -1
        cnt++;

        for (int i = 0; i < 3; i++)
        {
            if (search[i] < 100001 && search[i] >=0)
            {
                if (search[i] == K)
                {
                    cout << cnt;
                    return ;
                }
                if (!visited[search[i]])
                {
                    q.push(make_pair(search[i], cnt));
                    visited[search[i]] = true;
                }
            }
        }
    }
}

int main()
{
    input();
    solution();

    return 0;
}
