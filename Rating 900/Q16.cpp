#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    // Minimum Case Calculation
    long long ansmin = LLONG_MAX;
    long long rem6 = n % 6;
    if (rem6 == 0)
    {
        ansmin = n / 6;
    }
    else if (rem6 == 2 && n >= 8)
    {
        ansmin = (n - 8) / 6 + 2;
    }
    else if (rem6 == 4 && n >= 4)
    {
        ansmin = (n - 4) / 6 + 1;
    }

    // Maximum Case Calculation
    long long ansmax = 0;
    if (n % 4 == 0)
    {
        ansmax = n / 4;
    }
    else if (n >= 6 && n % 4 == 2)
    {
        ansmax = (n - 6) / 4 + 1;
    }

    if (ansmin == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ansmin << " " << ansmax << endl;
    }
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
