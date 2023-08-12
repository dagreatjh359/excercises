// BOJ 4963
#include <iostream>
#include <stdbool.h>

using namespace std;

int w, h;
int map[51][51];
bool visitied[51][51];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void reset(int w, int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            map[i][j] = 0;
            visitied[i][j] = false;
        }
    }
}

void dfs(int y, int x)
{
    visitied[y][x] = true;

    for (int i = 0; i < 8; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 1 || nextX > w || nextY < 1 || nextY > h)
            continue;
        else
        {
            if (!visitied[nextY][nextX] && map[nextY][nextX] == 1)
            {
                visitied[nextY][nextX] = true;
                dfs(nextY, nextX);
            }
        }
    }
}

int main()
{
    cin >> w >> h;

    while (w != 0 && h != 0)
    {
        int res = 0;
        // get map
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> map[i][j];
            }
        }

        // dfs
        for (int n = 1; n <= h; n++)
        {
            for (int m = 1; m <= w; m++)
            {
                if (map[n][m] == 1 && !visitied[n][m])
                {
                    dfs(n, m);
                    res++;
                }
            }
        }
        cout << res << "\n";

        cin >> w >> h;
        reset(w, h);
    }

    return 0;
}
