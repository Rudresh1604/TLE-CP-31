#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxi = 0;

    // fix a[0] then rotate form 2 -> n;
    for (int i = 1; i < n; i++)
        maxi = max(maxi, a[i] - a[0]);
    // fix a[n] then rotate from 1->n-1
    for (int i = 0; i < n - 1; i++)
        maxi = max(maxi, a[n - 1] - a[i]);
    // take the entire segment and rotate it
    for (int i = 0; i < n - 1; i++)
    {
        maxi = max(maxi, a[i] - a[i + 1]);
    }

    cout << maxi << endl;
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