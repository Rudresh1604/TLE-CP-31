#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = arr[0];
    for (int i = 0; i < n - 1; i++)
    {

        ans = max(arr[i + 1] - arr[i], ans);
    }
    ans = max(ans, 2 * (x - arr[n - 1]));
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