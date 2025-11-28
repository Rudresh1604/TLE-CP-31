#include <bits/stdc++.h>
using namespace std;

void myfun()
{
    long n, k;
    cin >> n >> k;
    vector<long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long ans = 1e9;
    int evenc = 0;
    for (int i = 0; i < n; i++)
    {
        long req = arr[i] % k;
        if (req == 0)
        {
            ans = 0;
            break;
        }
        req = k - req;
        if (arr[i] % 2 == 0)
            evenc++;
        ans = min(ans, req);
    }
    if (k == 4)
    {
        if (evenc >= 2)
            ans = 0;
        else if (evenc == 1)
            ans = min(ans, (long)1);
        else
            ans = min(ans, (long)2);
    }
    cout << ans << endl;
}

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        myfun();
    }
}