#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long a, b, c;
    cin >> a >> b >> c;
    // a+c = 2*b
    // so we can either do a*m or b*m or c*m
    long m = -1;
    if ((a + c) % (2 * b) == 0)
    {
        // m *b case
        cout << "YES" << endl;
        return;
    }
    if ((2 * b - c) % a == 0 && (2 * b - c) > 0)
    {
        // m *a case
        cout << "YES" << endl;
        return;
    }
    if ((2 * b - a) % c == 0 && (2 * b - a) > 0)
    {
        // m *c case
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