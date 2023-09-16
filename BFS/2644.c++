// BOJ 2644
#include <iostream>
#include <vector>

using namespace std;

int N, E, a, b;

typedef struct node
{
    int id;
    bool visited;
    int dis = 0;
    vector<int> v;
} node;
vector<node> nodes(101);
vector<node> q;
int cnt = 0;

void input()
{
    cin >> N;
    cin >> a >> b;
    cin >> E;

    for (int i = 0; i < E; i++)
    {
        int p, c;
        cin >> p >> c;
        nodes[p].v.push_back(c);
        nodes[c].v.push_back(p);
        nodes[p].visited = false;
        nodes[p].id = p;
    }
}

void solution()
{
    q.push_back(nodes[a]);
    nodes[a].visited = true;

    while (!q.empty())
    {
        node curr = q.front();
        q.erase(q.begin());

        for (int i = 0; i < curr.v.size(); i++)
        {
            if(!nodes[curr.v[i]].visited)
            {
                nodes[curr.v[i]].visited = true;
                nodes[curr.v[i]].dis = curr.dis + 1;
                q.push_back(nodes[curr.v[i]]);
            }
            if(nodes[curr.v[i]].id == b)
                break;
        }
    }
    if(nodes[b].dis != 0) 
    {
        cout << nodes[b].dis;
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    input();
    solution();
}
