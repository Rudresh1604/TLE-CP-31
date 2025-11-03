#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long num;
    cin >> num;
    long op = 0;
    while (num > 1 && num % 6 == 0)
    {
        num = num / 6;
        op++;
    }
    if (num == 1)
    {
        cout << op << endl;
        return;
    }
    while (num > 1 && num % 3 == 0)
    {
        num = num / 3;
        op += 2;
    }
    if (num != 1)
    {
        cout << -1 << endl;
        return;
    }
    cout << op << endl;
}

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}