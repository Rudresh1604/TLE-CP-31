#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, k;
    cin >> n >> k;
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p == k)
        {
            f = 1;
        }
    }
    if (f)
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