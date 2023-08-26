// BOJ 14888 brute force
#include <iostream>
#include <vector>

using namespace std;

int p, m, x, d;
int N;
int a[101];
int maximum = -1000000001;
int minimum = 1000000001;

void brute_force(int num1, int num2, int idx)
{
    if (idx == N + 1)
    {
        if (num1 > maximum)
        {
            maximum = num1;
        }

        if (num1 < minimum)
        {
            minimum = num1;
        }
        return;
    }

    int next = idx+1;

    if (p > 0)
    {
        --p;
        brute_force(num1 + num2, a[idx], next);
        ++p;
    }
    if (m > 0)
    {
        --m;
        brute_force(num1 - num2, a[idx], next);
        ++m;
    }
    if (x > 0)
    {
        --x;
        brute_force(num1 * num2, a[idx], next);
        ++x;
    }
    if (d > 0)
    {
        --d;
        brute_force(num1 / num2, a[idx], next);
        ++d;
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    
    cin >> p >> m >> x >> d;

    brute_force(a[0], a[1], 2);

    cout << maximum << "\n"
         << minimum;

    return 0;
}
