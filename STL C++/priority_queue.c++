// BOJ 11279
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> heap;
    vector<int> result;

    for(int i=0;i<N;i++)
    {
        int in;
        cin >> in;

        if(in == 0 && heap.empty())
        {
            result.push_back(0);
        }
        else if(in == 0 && !heap.empty())
        {
            result.push_back(heap.top());
            heap.pop();
        }
        else
        {
            heap.push(in);
        }
    }

    for(int j=0;j<result.size();j++)
    {
        cout << result[j] <<"\n";
    }
    return 0;
}
