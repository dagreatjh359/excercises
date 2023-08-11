//BOJ 2606
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> matrix(101, vector<int>(101,0));
stack<int> s;
vector<bool> visited(101, false);

int dfs(int V, int N)
{
    int res = 0;

    s.push(V);
    visited[V] = true;
    //cout << V << " ";
    
    while(!s.empty())
    {
        V = s.top();
        bool depth = false;
        
        for(int i=1;i<=N;i++)
        {
            if(matrix[V].at(i) == 1 && !visited[i])
            {
                //cout << i << " ";
                res++;
                visited[i] = true;
                s.push(i);
                depth = true;

                break;
            }
        }
        if(!depth)
        {
            s.pop();
        }
    }

    return res;
}

int main()
{
    int N, E;

    cin >> N;
    cin >> E;

    for (int i =0;i<E;i++)
    {
        int v1,v2;

        cin >> v1 >> v2;

        matrix[v1].at(v2) = 1;
        matrix[v2].at(v1) = 1;
    }

    fill(visited.begin(), visited.begin() + N,false);
    cout << dfs(1, N);
    
    return 0;
}
