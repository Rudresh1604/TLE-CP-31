#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long m;
    cin >> m;

    vector<long long> first, sec;

    while (m--)
    {
        int n;
        cin >> n;

        long long min1 = LLONG_MAX, min2 = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;

            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
            {
                min2 = x;
            }
        }

        first.push_back(min1);
        sec.push_back(min2);
    }

    long long ans = 0;
    long long mn1 = LLONG_MAX;
    long long m2 = LLONG_MAX;

    for (int i = 0; i < sec.size(); i++)
    {
        mn1 = min(mn1, first[i]);
        m2 = min(m2, sec[i]);
        ans += sec[i];
    }

    ans = ans - m2 + mn1;
    cout << ans << endl;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}