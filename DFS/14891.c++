// BOJ 14891 with DFS
#include <iostream>
#include <cmath>

using namespace std;

int gear[4][8];
int N;
int sum = 0;

void input()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ns;
            cin >> ns;
            gear[i][j] = ns - '0';
        }
    }
    cin >> N;
}

void spin(int gear[], int turn)
{
    if (turn == 1)
    {
        int end = gear[7];
        for (int i = 7; i > 0; i--)
        {
            gear[i] = gear[i - 1];
        }
        gear[0] = end;
    }
    else
    {
        int top = gear[0];
        for (int i = 0; i < 7; i++)
        {
            gear[i] = gear[i + 1];
        }
        gear[7] = top;
    }
}

void check_r(int gear_n, int turn)
{
    if (gear[gear_n][2] != gear[gear_n + 1][6] && gear_n + 1 < 4)
    {
        check_r(gear_n + 1, !turn);
    }
    spin(gear[gear_n], turn);
}
void check_l(int gear_n, int turn)
{
    if (gear[gear_n][6] != gear[gear_n - 1][2] && gear_n - 1 >= 0)
    {
        check_l(gear_n - 1, !turn);
    }
    spin(gear[gear_n], turn);
}

int main()
{
    input();

    for (int i = 0; i < N; i++)
    {
        int gear_in, turn;
        cin >> gear_in >> turn;

        if (turn == -1)
        {
            turn = 0;
        }
        int gear_n = gear_in - 1;

        if (gear[gear_n][2] != gear[gear_n + 1][6] && gear_n + 1 < 4)
        {
            check_r(gear_n + 1, !turn);
        }
        if (gear[gear_n][6] != gear[gear_n - 1][2] && gear_n - 1 >= 0)
        {
            check_l(gear_n - 1, !turn);
        }
        spin(gear[gear_n], turn);
    }

    for (int i = 0; i < 4; i++)
    {
        if (gear[i][0] == 1)
            sum += pow(2, i);
    }
    cout << sum;
}
