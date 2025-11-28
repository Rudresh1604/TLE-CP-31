#include <bits/stdc++.h>
using namespace std;

#define l long long

int main()
{
    l n, k, qs;
    cin >> n >> k >> qs;

    vector<pair<l, l>> temp(n);
    vector<pair<l, l>> q(qs);

    l mini = 1e15, mxi = -1e15;

    for (l i = 0; i < n; i++)
    {
        cin >> temp[i].first >> temp[i].second;
        mini = min(mini, temp[i].first);
        mxi = max(mxi, temp[i].second);
    }

    for (l i = 0; i < qs; i++)
    {
        cin >> q[i].first >> q[i].second;
    }

    l len = (mxi - mini + 5);

    vector<l> trange(len, 0);

    for (l i = 0; i < n; i++)
    {
        l lft = temp[i].first - mini;
        l rht = temp[i].second - mini;

        if (lft >= 0 && lft < len)
            trange[lft]++;

        if (rht + 1 < len)
            trange[rht + 1]--;
    }

    vector<l> cnt(len, 0);

    trange[0] = trange[0];
    cnt[0] = (trange[0] >= k);

    for (l i = 1; i < len; i++)
    {
        trange[i] = trange[i - 1] + trange[i];
        cnt[i] = cnt[i - 1] + (trange[i] >= k);
    }

    for (auto it : q)
    {
        l lft = it.first - mini;
        l rht = it.second - mini;

        l L = max(0LL, lft);
        l R = min(len - 1, rht);

        if (L > R)
        {
            cout << 0 << "\n";
            continue;
        }

        l ans = cnt[R];
        if (L > 0)
            ans -= cnt[L - 1];

        cout << ans << "\n";
    }

    return 0;
}
