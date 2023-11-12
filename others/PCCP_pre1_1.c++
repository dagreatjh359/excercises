#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

string solution(string input_string) {
    
    string in = input_string;
    string answer = "";
    bool visited[2000];
    
    for(int i=0;i<in.size();i++)
    {
        for(int j=i+1;j<in.size();j++)
        {
            if(in[i] == in[j] && j-i > 1 && in[j-1] != in[i] && !visited[in[i]])
            {
                ans.push_back(in[i]);
                visited[in[i]] = true;
                break;
            }
        }
    }
    if(ans.empty())
        answer = "N";
    else
    {
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
        {
            answer.push_back(ans[i]);
        }
    }
    
    return answer;
}
