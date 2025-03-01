#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    else if (n == 2 && k == 1)
    {
        cout << "YES" << endl;
        return;
    }
    vector<int> fre(26, 0);
    for (int i = 0; i < n; i++)
    {
        fre[s[i] - 'a']++;
    }
    long sum = 0;
    for (int i = 0; i < 26; i++)
    {
        fre[i] = fre[i] % 2;
        sum += fre[i];
    }
    if (n == 3 && sum == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (sum - k > 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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