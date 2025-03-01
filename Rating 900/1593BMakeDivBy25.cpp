#include <bits/stdc++.h>
using namespace std;

long opr(string &s, string &tar)
{
    long long ans = 0, n = s.size();
    long long j = n - 1;
    while (j > 0 && s[j] != tar[1])
    {
        j--;
        ans++;
    }
    long long i = j - 1;
    while (i > 0 && s[i] != tar[0])
    {
        i--;
        ans++;
    }
    return ans;
}

void fun()
{
    // logic is to make last 2 digits 00 or 25 or 75 or 50
    long long n;
    cin >> n;
    string s = to_string(n);
    vector<string> tar = {"00", "25", "75", "50"};
    long long ans = 1e18 + 1;
    for (auto it : tar)
    {
        long long cur = opr(s, it);
        ans = min(cur, ans);
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
