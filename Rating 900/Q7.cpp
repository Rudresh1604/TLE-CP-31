#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n, k;
    cin >> n >> k;
    vector<long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long maxi = 0, cur = 0;
    for (int i = 1; i < n; i++)
    {
        long dif = arr[i] - arr[i - 1];
        if (dif <= k)
        {
            cur++;
            maxi = max(maxi, cur);
        }
        else
        {
            cur = 0;
        }
    }
    cout << n - maxi - 1 << endl;
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