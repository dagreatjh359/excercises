// BOJ 5014 very same with BOJ 1697
#include <iostream>
#include <queue>

using namespace std;
bool visited[1000001];
queue<pair<int, int>> q;
int F, S, G, U, D;

void input()
{
    cin >> F >> S >> G >> U >> D;
    fill_n(visited, 1000001, false);
    q.push(make_pair(S, 0));
    visited[S] = true;
}

void solution()
{
    if (S == G)
    {
        cout << 0;
        return;
    }

    if((S < G && U == 0) || S > G && D == 0)
    {
        cout << "use the stairs";
        return;
    }

    while (!q.empty())
    {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        int search[2] = {curr + U, curr - D};
        cnt++;

        for (int i = 0; i < 2; i++)
        {
            if (search[i] >= 1 && search[i] <= F)
            {
                if (search[i] == G)
                {
                    cout << cnt;
                    return;
                }
                if (!visited[search[i]])
                {
                    q.push(make_pair(search[i], cnt));
                    visited[search[i]] = true;
                }
            }
        }
    }
    cout << "use the stairs";
}

int main()
{
    input();
    solution();

    return 0;
}
