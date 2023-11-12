#include <string>
#include <vector>

using namespace std;

vector<vector<int>> *ab;
bool visited[11];
int sum, maximum = -1;

void dfs(int col)
{
    if(col == (*ab)[0].size())
    {
        maximum = maximum < sum ? sum : maximum;
        return;
    }
    for(int i=0;i<(*ab).size();i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            sum += (*ab)[i][col];
            dfs(col+1);
            sum -= (*ab)[i][col];
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    ab = &ability;
    fill_n(visited, ability.size(), false);
    
    dfs(0);
    
    answer = maximum;
    return answer;
}
