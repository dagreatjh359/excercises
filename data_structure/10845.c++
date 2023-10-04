// BOJ 10845
#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> q;
int N,n;
string in;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> in;

        if (in == "push")
        {
            cin >> n;
            q.push(n);
        }
        else if (in == "pop")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (in == "front")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (in == "back")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
        else if (in == "empty")
        {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (in == "size")
        {
            cout << q.size() << "\n";
            ;
        }
    }
}
