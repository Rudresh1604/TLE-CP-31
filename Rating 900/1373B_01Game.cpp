#include <bits/stdc++.h>
using namespace std;

void fun()
{
    string s;
    cin >> s;
    long n = s.size();
    long one = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }
    long moves = min(one, zero);
    if (moves % 2 != 0)
    {
        cout << "DA" << endl;
    }
    else
    {
        cout << "NET" << endl;
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