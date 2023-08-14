// BOJ 1541
#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

string s;
string t = "";
bool minus_f = false;

int main()
{
    cin >> s;

    int res = 0;

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] != '-' && s[i] != '+' && i != s.size()){
            t = t + s[i];
        }
        else
        {
            if (minus_f){
                res = res - stoi(t);
            }
            else{
                res = res + stoi(t);
            }

            if (s[i] == '-')
                minus_f = true;

            t = "";
        }
    }

    cout << res;

    return 0;
}