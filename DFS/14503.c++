// BOJ 14503
#include <iostream>

using namespace std;

int N, M;
int y, x;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int start;
bool first_toward = true;
int maze[51][51];
int clean = 0;

void input()
{
    cin >> N >> M;
    cin >> y >> x >> start;

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

void solution(int y, int x, int face)
{
    if (maze[y][x] == 0)
    {
        maze[y][x] = -1;
        clean++;
    }

    for (int i = 3; i >= 0; i--)
    {
        int n_face = (face + i) % 4;
        int nx = x + dx[n_face];
        int ny = y + dy[n_face];

        if (maze[ny][nx] == 0 && 0 <= y && y <= N && 0 <= x && x <= M)
        {
            solution(ny, nx, n_face);
        }
    }

    int b_face = (face + 2) % 4;
    int bx = x + dx[b_face];
    int by = y + dy[b_face];
    if (maze[by][bx] == 1)
    {
        cout << clean;
        exit(0);
    }
    solution(by, bx, face);
}

int main()
{
    input();
    solution(y, x, start);
    cout << clean;
}
