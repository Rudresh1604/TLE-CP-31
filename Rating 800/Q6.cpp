#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    bool f = 0;
    for (int i = 0; i <= 5; i++)
    {
        if (x.find(s) != string::npos)
        {
            cout << i << endl;
            f = 1;
            break;
        }
        x += x;
    }
    if (!f)
    {
        cout << "-1" << endl;
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