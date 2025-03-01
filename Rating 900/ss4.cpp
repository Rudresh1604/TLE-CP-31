#include <bits/stdc++.h>
using namespace std;

void fun()
{
    // https://codeforces.com/problemset/problem/1666/D
    string s1, s2;
    cin >> s1 >> s2;
    vector<long> mpp1(26, 0), mpp2(26, 0);
    for (long i = 0; i < s2.size(); i++)
    {
        mpp2[s2[i] - 'A']++;
    }

    string s = "";
    for (long i = 0; i < s1.size(); i++)
    {

        if (mpp2[s1[i] - 'A'] > 0)
        {
            s += s1[i];
            mpp1[s1[i] - 'A']++;
        }
    }
    s1 = s;
    // cout << s1 << " " << s2 << endl;
    long n = s1.size(), m = s2.size();
    if (n < m)
    {
        cout << "NO" << endl;
        return;
    }
    long i = 0, j = 0;
    long cnt = 0;
    while (i < n && j < m)
    {
        if (s1[i] == s2[j] && mpp1[s1[i] - 'A'] == mpp2[s2[j] - 'A'] && mpp1[s1[i] - 'A'] > 0)
        {
            cnt++;
            mpp1[s1[i] - 'A']--;
            mpp2[s2[j] - 'A']--;
            i++;
            j++;
        }
        else
        {
            mpp1[s1[i] - 'A']--;
            i++;
        }
    }
    if (cnt == m)
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
    long long t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
