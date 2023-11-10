//BOJ 1802
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;
string in;
deque<string> answer;

bool solution(int size)
{
    if(size == 1)
        return true;

    for(int i=0;i<size/2;i++)
    {
        int pair_idx = size-1 - i;

        if(in[pair_idx] == in[i])
            return false;
    }
    if(!solution(size/2))
        return false;
    else
        return true;
}

int main()
{
    cin >> T;
    cin.ignore();

    for(int i=0;i<T;i++)
    {
        getline(cin, in);
        if(solution(in.size()))
            answer.push_back("YES");
        else
            answer.push_back("NO");
    }

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}
