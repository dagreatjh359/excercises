//BOJ 1026

#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a>b;
}

int main()
{
    int N;
    int A[50];
    int B[50];

    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    for(int j = 0; j<N;j++)
    {
        cin >> B[j];
    }

    sort(A,A+N);
    sort(B,B+N, desc);

    int res = 0;

    for(int i=0;i<N;i++)
    {
        res = res + A[i]*B[i];
    }

    cout << res;
    
    return 0;
}
