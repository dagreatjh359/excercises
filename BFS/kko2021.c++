// https://school.programmers.co.kr/learn/courses/30/lessons/81302?language=cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    pair<int, int> p(0,0);
    pair<int, int> tmp;

    vector<pair <int, int>> q;
    int visited[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            visited[i][j] = 0;
    }
    q.push_back(p);

    while(!q.empty())
    {
        tmp = q.front();
        q.erase(q.begin());

        for(int i=0;i<4;i++)
        {
            if(tmp.first + dx[i] >= 0 && tmp.second + dx[i] < 5 && tmp.first + dy[i] >=0 && tmp.second + dy[i] < 5)
            {

            }
        }

    }

    return answer;
}
