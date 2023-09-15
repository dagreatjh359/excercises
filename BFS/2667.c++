// BOJ 2667 - BFS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;
int map[25][25];
int visited[25][25];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<int> flats;

typedef struct pt
{
    int x;
    int y;
} pnt;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < N; j++)
        {
            map[i][j] = tmp[j] - '0';
            visited[i][j] = 0;
        }
    }
}

bool inboud(int x, int y)
{
    if (0 <= x && x < N && 0 <= y && y < N)
        return true;
    else
        return false;
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                vector<pnt> q;
                pnt start;
                start.x = i;
                start.y = j;
                visited[i][j] = 1;
                cnt++;

                q.push_back(start);
                while (!q.empty())
                {
                    pnt curr = q.front();
                    q.erase(q.begin());

                    for (int i = 0; i < 4; i++)
                    {
                        int new_x = curr.x + dx[i];
                        int new_y = curr.y + dy[i];
                        if (inboud(new_x, new_y))
                        {
                            if (map[new_x][new_y] == 1 && !visited[new_x][new_y])
                            {
                                cnt++;
                                pnt new_p;
                                new_p.x = new_x;
                                new_p.y = new_y;
                                q.push_back(new_p);
                                visited[new_x][new_y] = 1;
                            }
                        }
                    }
                }
                flats.push_back(cnt);
                cnt = 0;
            }
        }
    }
}

int main()
{
    input();
    solution();
    sort(flats.begin(), flats.end());

    cout << flats.size() << '\n';

    for (int i = 0; i < flats.size(); i++)
    {
        cout << flats[i] << '\n';
    }
}
