#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        n = n / 2;
        if (n == 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << (n / 3 + (n % 3 != 0 ? 1 : 0)) << " " << n / 2 << endl;
        }
    }
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