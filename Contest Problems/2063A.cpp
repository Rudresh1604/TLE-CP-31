#include <bits/stdc++.h>
using namespace std;

void fun()
{
    // coprime if gcd(x,y) = 1
    // observation is that the minimal subsequnce will be always x , x+1
    // so the total no of minimal subsequnce in range l and r will be
    // r-l
    // except for 1 the total no of minimal subsequnce will be 1
    long l, r;
    cin >> l >> r;
    if (l == 1 && r == 1)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << r - l << endl;
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