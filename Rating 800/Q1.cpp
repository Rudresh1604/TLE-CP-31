#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void fun()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        }
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (checkSorted(arr))
    {
        cout << "YES" << endl;
    }
    else
    {
        if (k <= 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
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