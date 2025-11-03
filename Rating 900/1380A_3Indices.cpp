#include <bits/stdc++.h>
using namespace std;

void optimal()
{
    long n;
    cin >> n;
    vector<long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = true;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            cout << "YES" << endl;
            flag = false;
            cout << i << " " << i + 1 << " " << i + 2 << endl;
            break;
        }
    }
    if (flag == false)
    {
        cout << "NO" << endl;
    }
}

void fun()
{
    long n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int j = 1; j < n - 1; j++)
    {
        int l = -1, r = -1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (arr[i] < arr[j])
            {
                l = i;
                break;
            }
        }
        for (int k = j + 1; k < n; k++)
        {
            if (arr[k] < arr[j])
            {
                r = k;
                break;
            }
        }
        if (l != -1 && r != -1)
        {
            cout << "YES" << endl;
            cout << l + 1 << " " << j + 1 << " " << r + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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