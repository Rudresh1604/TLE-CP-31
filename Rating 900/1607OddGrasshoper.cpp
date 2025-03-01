#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long x, n;
    cin >> x >> n;
    // its observation based problem
    // after performing the operation for 4 times we get x as it is
    // so based on the remainder following results are observed
    if (n % 4 == 0)
    {
        cout << x << endl;
    }
    else if (n % 4 == 3)
    {
        if (x % 2 == 0)
        {
            cout << x + n + 1 << endl;
        }
        else
        {
            cout << x - n - 1 << endl;
        }
    }
    else if (n % 4 == 2)
    {
        if (x % 2 == 0)
        {
            cout << x + 1 << endl;
        }
        else
        {
            cout << x - 1 << endl;
        }
    }
    else
    {
        if (x % 2 == 0)
        {
            cout << x - n << endl;
        }
        else
        {
            cout << x + n << endl;
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