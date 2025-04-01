#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n, k;
    cin >> n >> k;
    long siz = n * k + 1;
    vector<long> arr(siz);
    arr[0] = 0;
    for (long i = 1; i <= n * k; i++)
        cin >> arr[i];

    long long ans = 0;
    long m = n / 2;

    long ind = n * k - m;
    while (k--)
    {

        ans += arr[ind];
        ind = ind - m - 1;
    }
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