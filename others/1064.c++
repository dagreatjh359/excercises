//BOJ 1064
#include <iostream>
#include <cmath>
#include <iomanip> //for setpercision

using namespace std;

double p[2][3];
double dx1, dx2, dy1, dy2, dx3, dy3;
double a, b, c;
double res;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0)
        {
            p[0][i / 2] = tmp;
        }
        else
        {
            p[1][i / 2] = tmp;
        }
    }

    dx1 = p[0][0] - p[0][1];
    dy1 = p[1][0] - p[1][1];

    dx2 = p[0][1] - p[0][2];
    dy2 = p[1][1] - p[1][2];

    dx3 = p[0][0] - p[0][2];
    dy3 = p[1][0] - p[1][2];

    double grad1;
    double grad2;

    if(dx1==0){
        grad1 = 1e9;
    }
    else{
        grad1= abs(dy1/dx1);
    }

    if(dx2==0){
        grad2 = 1e9;
    }
    else{
        grad2= abs(dy2/dx2);
    }

    if (grad1 == grad2)
    {
        res = -1;
        cout << setprecision(1) << res;
        return 0;
    }

    a = (double)sqrt(dx1 * dx1 + dy1 * dy1);
    b = (double)sqrt(dx2 * dx2 + dy2 * dy2);
    c = (double)sqrt(dx3 * dx3 + dy3 * dy3);

    if (a < b)
    {
        swap(a, b);
    }
    if (a < c)
    {
        swap(a, c);
    }
    if (b < c)
    {
        swap(b, c);
    }

    res = 2 * (a - c);

    cout << setprecision(17) << res;
}
