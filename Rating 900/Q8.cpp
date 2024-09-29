#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = 0;
    if (s[0] == '<')
    {
        flag = 1;
    }
    long maxi = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!flag)
        {
            if (s[i] == '>')
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                flag = 1;
            }
        }
        else
        {
            if (s[i] == '<')
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                flag = 0;
            }
        }
        maxi = max(maxi, cnt);
    }
    cout << maxi + 1 << endl;
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