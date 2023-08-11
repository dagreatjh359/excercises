// BOJ 1260 bfs, dfs
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int matrix[1001][1001];
int visited[1001];

//dfs with stack
void dfs(int V, int N)
{
    stack<int> s;

    s.push(V);
    visited[V] = 1;
    cout << V << " ";

    while (!s.empty())
    {
        int target_vertex = s.top();
        bool exist_subdepth = false;

        for (int i = 1; i <= N; i++)
        {
            if (matrix[target_vertex][i] == 1 && visited[i] != 1)
            {
                cout << i << " ";
                s.push(i);

                visited[i] = 1;
                exist_subdepth = true;

                break;
            }
        }
        if (!exist_subdepth)
            s.pop();
    }
}

void reset(int N) {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}
/*
dfs with recursion
void dfs(int V, int N)
{
    visited[V] = 1;
    cout << V << " ";

    for(int i =1 ;i<=N;i++)
    {
        if(visited[i] ==0 && matrix[V][i] == 1)
        {
            dfs(i,N);
        }
    }
}*/

void bfs(int V, int N)
{
    queue<int> q;

    q.push(V);
    visited[V] = 1;
    
    while (!q.empty())
    {
        cout << q.front() << " ";

        int target_vertex = q.front();
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0 && matrix[target_vertex][i] == 1)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    int N, E, V;

    cin >> N >> E >> V;

    for (int i = 0; i < E; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }

    reset(N);
    dfs(V, N);
    cout << "\n";
    //fill(visited, visited + N + 1, 0);
    reset(N);
    bfs(V, N);

    return 0;
}