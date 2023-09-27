// BOJ 2573
#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int y;
    int x;
    int after;
} node;

int Y, X;
int H[301][301];
queue<node> afters;      // for changes
queue<pair<int, int>> q; // for BFS
bool visited[301][301];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void input()
{
    cin >> Y >> X;
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cin >> H[i][j];
        }
    }
    fill(&(visited[0][0]), &(visited[Y][X]), false);
}

bool all_is_zero()
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            if (H[i][j] != 0)
                return false;
        }
    }
    return true;
}

void solution()
{
    int year = 0;
    int areas = 0;

    while (!all_is_zero())
    {
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                if (H[i][j] != 0)
                {
                    int zero_around = 0;
                    for (int search = 0; search < 4; search++)
                    {
                        if (H[i + dy[search]][j + dx[search]] == 0)
                            zero_around++;
                    }
                    int res = H[i][j] >= zero_around ? H[i][j] - zero_around : 0;
                    afters.push(node{i, j, res});
                }
            }
        }

        while (!afters.empty())
        {
            node curr = afters.front();
            afters.pop();
            H[curr.y][curr.x] = curr.after;
        }
        year++;

        areas = 0;
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                if (H[i][j] != 0 && !visited[i][j])
                {
                    q.push(pair(i, j));
                    visited[i][j] = true;

                    while (!q.empty())
                    {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        for (int search = 0; search < 4; search++)
                        {
                            if (H[y + dy[search]][x + dx[search]] != 0 && !visited[y + dy[search]][x + dx[search]])
                            {
                                q.push(pair(y + dy[search], x + dx[search]));
                                visited[y + dy[search]][x + dx[search]] = true;
                            }
                        }
                    }
                    areas++;
                }
            }
        }
        if (areas >= 2)
        {
            cout << year;
            return;
        }

        fill(&(visited[0][0]), &(visited[Y][X]), false);
    }
    cout << 0;
    return;
}

int main()
{
    input();
    solution();
}
