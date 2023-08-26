//BOJ 15681 dp dfs tree
#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;
vector<int> lines[100001];
int dp[100001];
int query[100001];

int N;
int root;
int q;
int result = 1;

void make_tree(int me, int parent)
{
    for(int i=0;i<lines[me].size();i++)
    {
        if(lines[me][i] != parent)
        {
            make_tree(lines[me][i], me);
        }
    }
    if(parent != -1)
    {
        dp[parent] = dp[parent] + dp[me];
    }
}


int main()
{
    /*ios_base::sync_with_stdio(false);
     -> segregation of buffer between stdio and iostream
    cin.tie(0);
    cout.tie(0);*/
    fill_n(dp, 100001, 1);

    cin >> N >> root >> q;

    for(int i=0;i<N-1;i++)
    {
        int U, V;
        cin >> U >> V;

        lines[U].push_back(V);
        lines[V].push_back(U);
    }

    make_tree(root, -1);

    for(int i=0;i<q;i++)
    {
        int tmp;
        cin >> tmp;
        query[i] = tmp;
    }

    for(int i=0;i<q;i++)
    {
        cout << dp[query[i]] <<"\n";
    }

    return 0;
}
