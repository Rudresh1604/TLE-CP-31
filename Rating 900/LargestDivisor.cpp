#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isSorted(long arr[], long n)
{
    for (long i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}

bool even(long a)
{
    if (a % 2 == 0)
        return 1;
    return 0;
}
bool odd(long a)
{
    if (a % 2 != 0)
        return 1;
    return 0;
}
int gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int checkdigit(long n)
{
    int cnt = 0;
    while (n > 0)
    {
        int d = n % 10;
        if (d)
        {
            cnt++;
        }
        n = n / 10;
    }
    return cnt;
}

int getRange(int start, int n)
{
    if (n % start != 0)
        return 0;
    // if (n <= start)
    //     return 1;
    return 1 + getRange(start + 1, n);
}
void fun()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0" << endl;
        return;
    }
    int ans = getRange(1, n);
    cout << ans << endl;
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