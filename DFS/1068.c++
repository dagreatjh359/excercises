//BOJ 1068
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;


vector<int> node[51];
bool visited[51];
int N;
int dnode;
int cnt;

void dfs(int root)
{
    if(root == dnode){
        return;
    }
    visited[root] = true;

    if(node[root].size() == 0 || (node[root].size()==1 && node[root][0] == dnode))
        cnt++;
    
    for(int i=0;i<node[root].size();i++)
    {
        if(!visited[node[root][i]])
            dfs(node[root][i]);
    }

}

int main()
{
    int root_idx;
    cin >> N;
    
    int tmp;
    for(int i=0;i<N;i++)
    {
        cin >> tmp; // node i's parent is tmp;
        if(tmp == -1) //this part made everything bad NEVER MISS THE TYPO!
        {
            root_idx = i;
        }
        else{
            node[tmp].push_back(i);
        }
    }
    cin >> dnode;

    if(dnode == root_idx){
        cnt = 0;
    }
    else{
        dfs(root_idx);
    }
    
    cout << cnt;

    return 0;
}
