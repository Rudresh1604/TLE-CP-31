#include <bits/stdc++.h>
using namespace std;

void fun()
{
    string s, t;
    cin >> s >> t;
    // whenever in the qs it is asked that perform operation on prefix
    // then always traverse the string or array from backward
    vector<long> mpp(30, 0);
    for (int i = 0; i < t.size(); i++)
    {
        mpp[t[i] - 'A']++;
    }
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (mpp[s[i] - 'A'] > 0)
        {
            ans += s[i];
            mpp[s[i] - 'A']--;
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans == t)
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