#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = -1, r = -1;
    // find 1st and last occurance of non zero element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (l == -1 && r == -1)
            {
                l = i;
                r = i;
            }
            else
            {
                r = i;
            }
        }
    }
    if (l == -1 && r == -1)
    {
        cout << "0" << endl;
        return;
        // all ele are 0
    }
    // cout << l << " " << r << endl;
    // check whether there exist all non zero element together by checkin whether 0 exist or not

    for (int i = l; i <= r; i++)
    {
        if (arr[i] == 0)
        {
            cout << "2" << endl;
            return;
        }
    }
    // if all non zero element together

    cout << "1" << endl;
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