//BOJ 1072
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double X, Y, Z;
    cin >> X >> Y;

    int L = 1;
    int H = 1000000000; //1000000000
    int mid;
    int result = -1;
    Z = Y*100/X;
    Z = floor(Z);

    while(L <= H)
    {
        mid = (L+H)/2;

        double tmpZ = ((Y+mid)*100/(X+mid));
        tmpZ = floor(tmpZ);

        if(tmpZ > Z)
        {
            result = mid;
            H = mid - 1;
        }
        if(tmpZ <= Z)
        {
            L = mid + 1;
        }
    }

    cout << result;

    return 0;
}

