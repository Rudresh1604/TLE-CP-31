#include <bits/stdc++.h>
using namespace std;

void fun()
{
    string s;
    cin >> s;
    long long onecnt = 0, zcnt = 0;
    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            zcnt++;
        else
            onecnt++;
    }

    long tsiz = 0;
    for (long i = 0; i < s.size(); i++)
    {

        if (s[i] == '0' && onecnt > 0)
        {
            tsiz++;
            onecnt--;
        }

        else if (s[i] == '1' && zcnt > 0)
        {
            tsiz++;
            zcnt--;
        }
        else
        {
            break;
        }
    }

    cout << s.size() - tsiz << endl;
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