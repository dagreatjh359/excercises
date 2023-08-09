// BOJ 14501
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int t[20], p[20], m[20] = {0,};

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i] >> p[i];
    }
    
    int max_p = 0;
    for (int j = 1; j <= N; j++)
    {
        m[j] = max(max_p, m[j]);

        if(j+t[j]-1<=N){
            m[j+t[j]-1] = max(m[j-1]+p[j], m[j+t[j]-1]);
        }
        
        max_p = max(m[j],max_p);
    }

    cout << max_p;

    return 0;
}