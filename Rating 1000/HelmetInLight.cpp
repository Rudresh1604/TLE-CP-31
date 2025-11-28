#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n, p;
    cin >> n >> p;
    vector<long> chance(n);
    vector<pair<long, long>> chancecost;
    vector<pair<long, long>> share;
    for (int i = 0; i < n; i++)
        cin >> chance[i];

    for (int i = 0; i < n; i++)
    {
        long cur;
        cin >> cur;
        share.push_back({cur, i});
    }
    sort(share.begin(), share.end());
    long cptr = 0, ind = 1, people = 1;
    long long ans = p;
    chancecost.push_back({chance[share[0].second], share[0].first});

    while (people < n)
    {
        if (chancecost.size() == cptr)
        {
            ans += p;
            chancecost.push_back({chance[share[ind].second], share[ind].first});
            ind++;
            people++;
        }
        else
        {
            long cur = min(p, chancecost[cptr].second);
            ans += cur;
            if (cur == chancecost[cptr].second)
            {
                chancecost[cptr].first--;
            }
            if (chancecost[cptr].first == 0)
                cptr++;
            chancecost.push_back({chance[share[ind].second], share[ind].first});
            ind++;
            people++;
        }
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