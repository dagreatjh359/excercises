//BOJ 1920
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N,M;

    cin >> N;
    vector<int> n(N);

    for(int i=0;i<N;i++){
        cin >> n[i];
    }
    cin >> M;
    vector<int> m(M);

    for(int i=0;i<M;i++){
        cin >> m[i];
    }

    sort(n.begin(), n.end());

    for(int j=0;j<M;j++)
    {
        cout <<  binary_search(n.begin(), n.end(), m[j]) << " ";
    }

    return 0;
}