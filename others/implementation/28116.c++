// BOJ 28116
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int dist[500001];
int num[500001];
int idx[500001];

void mysort()
{
    int min, tmp;
    for (int i = 0; i < N; i++)
    {
        if (num[i] == i + 1)
            continue;
        dist[num[i]] += abs(idx[i + 1] - i);
        dist[num[idx[i + 1]]] += abs(idx[i + 1] - i);

        
        int tmpnum = num[i];
        int tmpnum2 = num[idx[i+1]];

        swap(num[i], num[idx[i+1]]);
        swap(idx[tmpnum], idx[tmpnum2]);
        

        /*
        int tmpArr = num[i];
        int tmpIdx = idx[num[i]];

        num[i] = num[idx[i + 1]];
        num[idx[i + 1]] = tmpArr;

        idx[tmpArr] = idx[i + 1];
        idx[i + 1] = tmpIdx;
        */
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        idx[num[i]] = i;
    }

    fill_n(dist, 5001, 0);

    mysort();

    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
