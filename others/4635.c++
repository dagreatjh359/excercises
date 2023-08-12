// BOJ 4635
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    std::vector<int> speed;
    std::vector<int> time;

    while (1)
    {
        int tmp1, tmp2, res = 0;

        std::cin >> N;
        if (N == -1)
            break;

        for (int i = 0; i < N; i++)
        {
            cin >> tmp1 >> tmp2;
            speed.push_back(tmp1);
            time.push_back(tmp2);
            if(i == 0)
            {
                res = res + speed.at(i) * time.at(i);
            }
            else{
                res = res + speed.at(i) * (time.at(i) - time.at(i-1));
            }
        }
        cout << res << " miles\n";

        speed.clear();
        time.clear();
    }
    return 0;
}