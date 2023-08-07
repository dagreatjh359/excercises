//BOJ 14501 front to back
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int t[20], p[20], m[20] ={0,};

    cin >> N;

    for(int i =1; i<=N;i++){
        cin >> t[i] >> p[i];
    }

    int max_p = 0;

    for(int i = 1; i<=N;i++)
    {
        m[i] = max(max_p, m[i]);
        if(i+t[i]<=N+1){
            m[i+t[i]] = max(m[i+t[i]], m[i]+p[i]);
        }
        max_p = max(m[i], max_p);
    }

    cout << max_p;

    return 0;
}