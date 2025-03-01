#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    int dx[] = {a, -a, a, -a, b, -b, -b, b};
    int dy[] = {b, -b, -b, b, a, -a, a, -a};
    set<pair<int, int>> st1, st2;
    for (int i = 0; i < 8; i++)
    {
        int curxk = xk + dx[i];
        int curxq = xq + dx[i];
        int curyk = yk + dy[i];
        int curyq = yq + dy[i];
        st1.insert({curxk, curyk});
        st2.insert({curxq, curyq});
    }
    long ans = 0;
    for (auto it : st1)
    {
        if (st2.find(it) != st2.end())
        {
            ans++;
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