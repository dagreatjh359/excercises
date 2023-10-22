// BOJ 15686
#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

int N, M;
int map[51][51];
int res = 987654321;
deque<pair<int, int>> chicken;
deque<pair<int, int>> tmp;
deque<pair<int, int>> home;
bool visited[51][51];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                chicken.push_back(pair(i, j));
                visited[i][j] = false;
            }
            if (map[i][j] == 1)
                home.push_back(pair(i, j));
        }
    }
}

void cal_distance()
{
    int total = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int m = 987654321;
        for (int j = 0; j < tmp.size(); j++)
        {
            int new_dis = abs(home[i].first - tmp[j].first) + abs(home[i].second - tmp[j].second);
            m = m > new_dis ? new_dis : m;
        }
        total += m;
    }
    if (total < res)
        res = total;
}

void combination(int start, int cnt)
{
    if (cnt == M)
    {
        // start brute force search for minimum
        cal_distance();
        return;
    }
    for (int i = start; i < chicken.size(); i++)
    {
        tmp.push_back(chicken[i]);
        cnt++;
        combination(i + 1, cnt);
        tmp.pop_back();
        cnt--;
    }
}

int main()
{
    input();
    combination(0, 0);
    cout << res;
}
