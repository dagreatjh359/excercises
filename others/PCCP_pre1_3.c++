#include <string>
#include <vector>

using namespace std;

string Rr[4] = {"RR", "Rr","Rr", "rr"};

string find_st(int n, int p, int idx)
{
    if(n == 2)
    {
        return Rr[idx-1];
    }
    
    int parent_n = n-1;
    int parent_p = p%4 == 0 ? p/4 : p/4+1;
    int parent_idx = parent_p%4 == 0 ? 4 : parent_p%4;
    string parent = find_st(parent_n, parent_p, parent_idx);
    
    if(parent == "RR")
    {
        return "RR";
    }
    else if(parent == "Rr")
    {
        return Rr[idx-1];
    }
    else
    {
        return "rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for(int i=0;i<queries.size();i++)
    {
        int n = queries[i][0];
        int p = queries[i][1];
        int idx = p%4 == 0 ? 4 : p%4;
        
        if(n == 1 && p == 1){
             answer.push_back("Rr");
        }
        else{
            answer.push_back(find_st(n, p, idx));
        }
    }
    
    return answer;
}
