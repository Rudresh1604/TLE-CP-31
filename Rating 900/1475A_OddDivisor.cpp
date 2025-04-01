#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long n;
    cin >> n;
    // Logic : if a number has odd divisor only if it contains all even divisor

    while (n > 2)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            break;
        }
    }
    if (n % 2 != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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