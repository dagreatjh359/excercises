// BOJ 1459
#include <iostream>
#define ll long long

using namespace std;

ll x, y, w, s;

ll solution()
{
    if(2*w <= s)
        return (x+y)*w;
    else
    {
        ll diagonal = y >=x ? x : y;
        ll vertical = 0;

        if(s >= w)
        {
            vertical = abs(x-y);
        }
        if(s < w)
        {
            if(abs(x-y)%2 == 0)
            {
                diagonal += abs(x-y);
            }
            else
            {
                diagonal += abs(x-y)-1;
                vertical++;
            }
        }
        return diagonal*s + vertical*w;
    }
}

int main()
{
    cin >> x >> y >> w >> s;
    cout << solution();
}
