#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long long a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if (a < b)
    {
        swap(a, b);
    }
    long long excit = a - b;
    long long op = b % excit;
    long long minop = min(op, abs(excit - op));
    cout << excit << " " << minop << endl;
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