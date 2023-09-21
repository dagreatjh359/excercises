// BOJ 7569
#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int t[101][101][101];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
bool flag = false;

typedef struct tomato_index
{
    int x, y, z, days =0;
} idx;

queue<idx> q;

bool inbound(int x, int y, int z)
{
    if (0 <= x && x < M && 0 <= y && y < N && 0 <= z && z < H)
        return true;
    else
        return false;
}

void solution()
{
    int res = 0;
    while (!q.empty())
    {
        idx curr = q.front();
        q.pop();

        res = curr.days;

        for (int i = 0; i < 6; i++)
        {
            int new_x = curr.x + dx[i];
            int new_y = curr.y + dy[i];
            int new_z = curr.z + dz[i];

            if (inbound(new_x, new_y, new_z) && t[new_z][new_y][new_x] == 0)
            {
                t[new_z][new_y][new_x] = 1;
                q.push(idx {new_x, new_y, new_z, res + 1});
            }
        }
    }
    bool there_is_zero = false;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (t[i][j][k] == 0)
                {
                    there_is_zero = true;
                    res = -1;
                    break;
                }
            }
            if (there_is_zero)
                break;
        }
        if (there_is_zero)
            break;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N >> H; // xyz

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> t[i][j][k];
                if (t[i][j][k] == 1)
                    q.push({k, j, i, 0});
                else if (t[i][j][k] == 0)
                    flag = true;
            }
        }
    }
    if (!flag)
    {
        cout << 0;
        return 0;
    }
    solution();
}
