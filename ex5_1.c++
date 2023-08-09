//BOJ 14501 - from back to front
//https://dinist.tistory.com/30
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

    for(int i =N; i>0;i--)
    {
        if(t[i]>N-i+1) {
            m[i] = m[i+1];
        }
        else{
            m[i] = max(p[i]+m[i+t[i]],m[i+1]);
        }
    }

    cout << m[1];

    return 0;
}
