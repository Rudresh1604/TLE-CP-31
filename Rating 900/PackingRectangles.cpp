#include <bits/stdc++.h>
using namespace std;

int main()
{
    long w, h, n;
    cin >> w >> h >> n;
    long l = 0, r = max(w, h) * n;
    long ans = max(w, h) * n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if ((floor(m / h) * floor(m / w)) >= n)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << endl;
}
