//BOJ 1021
#include <iostream>
#include <vector>

using namespace std;

vector<int> que;
int N, M, res = 0;

int find_index(int tmp)
{
    int i = 0;
    while(que.at(i) != tmp){
        if(que.at(i) == tmp){
            break;
        }
        i++;
    }
    return i;
}

void move_right(int p)
{
    int i = 0;

    while(i<p)
    {
        int tmp = que.back();
        for(int j=que.size()-2;j>=0;j--)
        {
            que[j+1] = que[j];
        }
        que[0] = tmp;
        i++;
    }
}

void move_left(int p)
{
    int i = 0;

    while(i<p)
    {
        int tmp = que.front();
        for(int j=1;j<que.size();j++)
        {
            que[j-1] = que[j];
        }
        que[que.size()-1] = tmp;
        i++;
    }
}

int main()
{
    cin >> N >> M;

    for(int i=0;i<N;i++){
        que.push_back(i+1);
    }
    
    for(int i=0;i<M;i++)
    {
        int tmp, pos;
        cin >> tmp;

        pos = find_index(tmp);

        N = que.size();

        if(pos > N/2)
        {
            res = res + (N-1)-pos+1;
            move_right(N-pos);
            que.erase(que.begin());
        }
        else
        {
            res = res + pos;
            move_left(pos);
            que.erase(que.begin());
        }
    }

    cout << res;
    
    return 0;
}
