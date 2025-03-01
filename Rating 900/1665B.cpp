#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n;
    cin >> n;
    vector<long> arr(n);
    unordered_map<long, long> mpp;
    for (long i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    long maxfre = 0, maxel = 0;
    for (auto it : mpp)
    {
        if (it.second > maxfre)
        {
            maxel = it.first;
            maxfre = it.second;
        }
    }
    // maxfre = equal
    long ans = 0;
    while (maxfre < n)
    {
        ans += 1 + min(maxfre, abs(n - maxfre));
        maxfre = maxfre * 2;
    }

    cout << ans << endl;
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