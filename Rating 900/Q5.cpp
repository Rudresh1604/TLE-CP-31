#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n;
    cin >> n;
    // if n is even
    // x^x^x^x = 0 & x^x^x=x
    // in case of even
    // so 1 oprn to make all equal and 1 oprn to make zero ===>> total = 2
    //                      1 to n and 1 to n
    //  for odd
    // a^b^c = x^x^c => 0^0^c => 0^0^0 so total 4 oprn
    // 1 to n => 2 to n => 1 to 2 => 1 to 2

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
    }

    if (n % 2 == 0)
    {
        cout << "2" << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    else
    {
        cout << "4" << endl;
        cout << 1 << " " << n << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
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