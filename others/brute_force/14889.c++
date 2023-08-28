//BOJ 14889
#include <iostream>
#include <vector>
#include <cmath>
#include <stdbool.h>

using namespace std;

int N;
int cap[21][21];
int gap;
int minimum = 2147483647; //INT_MAX
vector<int> st;
vector<int> link(21, 0);
bool visited[21];

void solve(int start, int cnt)
{
    if( cnt == N/2 )
    {
        int a=0;
        for(int k=1;k<=N;k++)
        {
            if(!visited[k])
            {
                link[a] = k;
                a++;
            }
        }

        int sum_st = 0;
        int sum_link = 0;

        for(int j=0;j<N/2-1;j++)
        {
            for(int k=j+1;k<N/2;k++)
            {
                sum_st = sum_st + cap[st[j]][st[k]] + cap[st[k]][st[j]];
                sum_link = sum_link + cap[link[j]][link[k]] + cap[link[k]][link[j]];
            }
        }
        gap = abs(sum_link - sum_st);

        if(gap < minimum)
            minimum = gap;

        return;
    }

    for(int i=start+1;i<=N;i++)
    {
        st.push_back(i);
        cnt++;
        visited[i] = true;
        solve(i, cnt);
        visited[i] = false;
        st.pop_back(); //important line
        cnt--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // -> segregation of buffer between stdio and iostream
    cin.tie(0);
    cout.tie(0);

    fill_n(visited, 21, false);

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int tmp;

            cin >> tmp;

            cap[i][j] = tmp;
        }
    }
    /*for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int tmp;

            cout << cap[i][j] << " ";
        }cout<<"\n";
    }cout<<"\n";*/

    st.push_back(1);
    visited[1] = true;
    solve(1, 1);

    cout << minimum;

    return 0;
}
