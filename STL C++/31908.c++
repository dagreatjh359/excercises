#include <iostream>
#include <vector>
#include <string>
#define MAXNUM 1000

using namespace std;

vector<vector<string>> table;//(MAXNUM+1, vector<string>());

int find(string ring, int idx)
{
    int i;
    bool found = false;
    for(i=0;i<idx;i++)
    {
        if(table[i][0] == ring)
        {
            found = true;
            break;
        }
    }
    return found == false ? -1 : i;
}

int main()
{
    int N;
    int idx = 0;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        string name;
        string ring;
        cin >> name >> ring;

        if(ring != "-")
        {
            int res = find(ring,idx);
            if(res ==-1)
            {
               // table[idx].push_back(ring);
               // table[idx].push_back(name);
                vector<string> tmp;
                tmp.push_back(ring);
                tmp.push_back(name);
                table.push_back(tmp);
                tmp.clear();
                idx++;
            }
            else
            {
                table[res].push_back(name);
            }
        }
    }

    int couples = 0;
    vector<vector<string>> result(MAXNUM+1,vector<string>());
    for(int i=0;i<idx;i++)
    {
        if(table[i].size() == 3)
        {
            result[couples].push_back(table[i][1]);
            result[couples].push_back(table[i][2]);
            couples++;
        }
    }
    cout << couples <<"\n";
    for(int i=0;i<couples;i++)
    {
        cout << result[i][0] << " " << result[i][1] << "\n";
    }

    return 0;
}
