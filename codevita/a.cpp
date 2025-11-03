#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull MAXLIM = (ull)9e18;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<string, long long>> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    ull k;
    cin >> k;

    long long base = 0;
    for (int i = 0; i < n; i++)
    {
        base += items[i].second * (i + 1);
    }

    unordered_map<string, long long> wmap;
    for (auto &it : items)
    {
        wmap[it.first] += it.second;
    }

    map<long long, vector<string>, greater<long long>> grp;
    for (auto &p : wmap)
    {
        grp[p.second].push_back(p.first);
    }

    vector<vector<string>> names;
    vector<long long> wts;
    for (auto &p : grp)
    {
        sort(p.second.begin(), p.second.end());
        names.push_back(p.second);
        wts.push_back(p.first);
    }

    int gcnt = names.size();
    vector<long long> allw;
    for (auto &p : wmap)
        allw.push_back(p.second);
    sort(allw.begin(), allw.end(), greater<long long>());

    long long best = 0;
    for (size_t i = 0; i < allw.size(); i++)
    {
        best += (i + 1) * allw[i];
    }

    cout << base + best << "\n";

    int maxsz = 0;
    for (auto &g : names)
        maxsz = max(maxsz, (int)g.size());

    vector<ull> fact(maxsz + 1, 1);
    for (int i = 1; i <= maxsz; i++)
    {
        if (fact[i - 1] > MAXLIM / i)
        {
            fact[i] = MAXLIM;
        }
        else
        {
            fact[i] = fact[i - 1] * i;
        }
    }

    vector<ull> suf(gcnt + 1, 1);
    for (int i = gcnt - 1; i >= 0; i--)
    {
        int sz = names[i].size();
        if (suf[i + 1] > MAXLIM / fact[sz])
        {
            suf[i] = MAXLIM;
        }
        else
        {
            suf[i] = suf[i + 1] * fact[sz];
        }
    }

    vector<string> res;
    for (int gi = 0; gi < gcnt; gi++)
    {
        ull blk = suf[gi + 1];
        ull idx = (k - 1) / blk;
        k = (k - 1) % blk + 1;

        vector<string> &v = names[gi];
        int m = v.size();
        vector<bool> used(m, false);
        ull rem = idx;

        for (int pos = 0; pos < m; pos++)
        {
            ull f = fact[m - 1 - pos];
            ull pick = (f == 0) ? 0 : rem / f;
            if (pick >= (ull)(m - pos))
                pick = m - pos - 1;
            rem = (f == 0) ? 0 : rem % f;

            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (used[j])
                    continue;
                if (cnt == (int)pick)
                {
                    res.push_back(v[j]);
                    used[j] = true;
                    break;
                }
                cnt++;
            }
        }
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        if (i)
            cout << " ";
        cout << res[i];
    }

    return 0;
}