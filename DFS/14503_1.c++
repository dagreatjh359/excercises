// BOJ 14503 with while loop
#include <iostream>

using namespace std;

int N, M;
int y, x;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int d;
int maze[51][51];
int clean = 0;

void input()
{
    cin >> N >> M;
    cin >> y >> x >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            maze[i][j] = ch - '0';
        }
    }
}

int main()
{
    input();

    while (1)
    {
        if (maze[y][x] == 0)
        {
            maze[y][x] = -1;
            clean++;
        }
        bool all_clean = true;
        for (int i = 3; i >= 0; i--)
        {
            int nd = (d + i) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if (maze[ny][nx] == 0 && 0 <= y && y <= N && 0 <= x && x <= M)
            {
                all_clean = false;
                x = nx;
                y = ny;
                d = nd;
                break;
            }
        }
        if (all_clean)
        {
            int bd = (d + 2) % 4;
            int bx = x + dx[bd];
            int by = y + dy[bd];
            if (maze[by][bx] == 1)
            {
                break;
            }
            else
            {
                x = bx;
                y = by;
            }
        }
    }
    cout << clean;
}
