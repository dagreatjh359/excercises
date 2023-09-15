// BOJ 2178 - BFS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct point
{
    int x;
    int y;
} point;

int N, M;
int maze[101][101];
int visited[101][101];
int res[101][101];
vector<point> q;

void input()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = row[j] - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            res[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    res[0][0] = 1;
    visited[0][0] = 1;
    point p;
    p.x = 0;
    p.y = 0;
    q.push_back(p);
}

void solve()
{
    while (!q.empty())
    {
        point p = q.front();
        q.erase(q.begin());
        int x = p.x, y = p.y;
        if (x - 1 >= 0 && maze[x - 1][y] && !visited[x-1][y])
        {
            point np1;
            np1.x = x - 1;
            np1.y = y;
            q.push_back(np1);
            
            res[x - 1][y] = res[x][y] + 1;
            visited[x-1][y] = 1;
        }
        if (x + 1 < N && maze[x + 1][y] && !visited[x + 1][y])
        {
            point np2;
            np2.x = x + 1;
            np2.y = y;
            q.push_back(np2);

            res[x + 1][y] = res[x][y] + 1;
            
            visited[x + 1][y] = 1;
        }
        if (y - 1 >= 0 && maze[x][y - 1] && !visited[x][y-1])
        {
            point np3;
            np3.x = x;
            np3.y = y - 1;
            q.push_back(np3);

            res[x][y - 1] = res[x][y] + 1;
            
            visited[x][y-1] = 1;
        }
        if (y + 1 < M && maze[x][y + 1] && !visited[x][y+1])
        {
            point np4;
            np4.x = x;
            np4.y = y + 1;
            q.push_back(np4);

            res[x][y + 1] = res[x][y] + 1;
            
            visited[x][y+1] = 1;
        }
    }
}

int main()
{
    input();
    solve();
    printf("%d", res[N-1][M-1]);
}
