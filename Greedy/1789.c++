//BOJ 1489
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    unsigned int S;
    cin >> S;

    long long sum = 0;
    long long idx = 1;

    while(1){
        sum = sum + idx;
        if(sum > S){
            idx--;
            break;
        }
        idx++;
    }

    cout << idx;

    return 0;
}
