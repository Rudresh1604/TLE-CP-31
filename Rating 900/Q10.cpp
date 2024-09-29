#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = __gcd(ans, abs(arr[i] - i));
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