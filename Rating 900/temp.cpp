#include <bits/stdc++.h>
using namespace std;

void fun()
{
    // minimum sum can be achieved only by selecting minimum elements of size r-l
    long n, l, r;
    cin >> n >> l >> r;
    vector<long> arr(n);
    for (long i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (long i = 0; i <= min(r - l, n); i++)
    {
        ans += arr[i];
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