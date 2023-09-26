// BOJ 2468 **very same with BOJ2667 -> but it does multiple searches according to the max height 
#include <iostream>
#include <queue>

using namespace std;

int N;
int area[101][101];
bool visited[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int H = 0;
int res = 0;

queue<pair<int, int>> q;  // y,x

void input()
{
    cin >> N;

    fill(&(visited[0][0]), &(visited[N][N]), false);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];

            if (H <= area[i][j])
                H = area[i][j];
        }
    }
}

bool inboud(int y, int x)
{
    if (0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

void solution()
{
    for (int rain = 0; rain <= H; rain++)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (area[i][j] > rain && !visited[i][j])
                {
                    q.push(make_pair(i,j)); // y,x

                    while (!q.empty())
                    {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        for (int idx = 0; idx < 4; idx++)
                        {
                            int new_x = x + dx[idx];
                            int new_y = y + dy[idx];
                            if (inboud(new_y, new_x))
                            {
                                if (area[new_y][new_x]  > rain && !visited[new_y][new_x])
                                {
                                    q.push(make_pair(new_y, new_x));
                                    visited[new_y][new_x] = true;
                                }
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        res = res < cnt ? cnt : res;
        fill(&(visited[0][0]), &(visited[N][N]), false);
    }
}

int main()
{
    input();
    solution();
    cout << res;
}
