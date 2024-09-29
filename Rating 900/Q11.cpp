#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<long> pre(n, 0);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        pre[i] = sum;
    }
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        long long temp = pre[r - 1];
        if (l > 1)
        {
            temp = temp - pre[l - 2];
        }
        long long req = sum - temp + (r - l + 1) * k;
        if (req % 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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