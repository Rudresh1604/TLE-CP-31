#include <bits/stdc++.h>
using namespace std;

void fun()
{
    string s;
    cin >> s;
    // aba then we get equal no of ab and ba
    // so if first and last are not equal then change them
    // and inside it (except first and last) can have any combinatons of aba or aa or ba or bb
    // hence it is proved that only first and last charcters need to be made equal
    int n = s.size();
    if (s[0] == s[n - 1])
    {
        cout << s << endl;
    }
    else
    {
        s[0] = s[n - 1];
        cout << s << endl;
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