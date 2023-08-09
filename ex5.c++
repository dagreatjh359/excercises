// BOJ 14501
// 예외가 존재하는 듯한 풀이 ---- 무지성!!!
#include <iostream>
using namespace std;

struct sd
{
    int begin;
    int time;
    int end;
    int pay;
} sd;

struct sd works[15];
int work_date[15];

void init_date(int date[], int total)
{
    for (int i = 1; i <= total; i++)
    {
        date[i] = 0;
    }
}

int check_available(struct sd sd, int date[])
{
    for (int i = sd.begin; i <= sd.end; i++)
    {
        if (date[i] == 1)
            return 0;
    }
    return 1;
}

int main()
{
    int N;

    init_date(work_date, N);

    cin >> N;
    for (int iter = 1; iter <= N; iter++)
    {
        cin >> works[iter].time;
        cin >> works[iter].pay;
        works[iter].begin = iter;
        works[iter].end = iter + works[iter].time - 1;
    }

    int i = 1;
    int max_income = 0;

    while (i <= N)
    {
        // check if non-scheduled are okay to be scheduled
        int zeros = 0;
        int non_avail = 0;
        for (int j = 1; j <= N; j++)
        {
            if (!work_date[j])
            {
                zeros++;
                non_avail = non_avail + !check_available(works[j], work_date);
            }
        }
        if (non_avail == zeros) // if number of non-scheduled and not okay to be scheduled are same break the loop
            break;
        // find max pay, min time
        int max_p = 0;
        int min_t = 0;
        int select_date;
        for (int p = 1; p <= N; p++)
        {
            if (work_date[p] == 0)
            {
                if (works[p].end > N || !check_available(works[p], work_date))
                {
                    work_date[p] = -1;
                }
                else if (max_p <= works[p].pay)
                {
                    max_p = works[p].pay;
                    min_t = works[p].time;
                    if (min_t >= works[p].time)
                    {
                        min_t = works[p].time;
                        select_date = p;
                    }
                }
            }
        }
        max_income = max_income + works[select_date].pay;
        for(int d = works[select_date].begin;d<=works[select_date].end;d++)
        {
            work_date[d] = 1;
        }
        i++;
    }
    cout << max_income;

    return 0;
}
