#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long n, x;
    cin >> n >> x;
    vector<long> arr(n);
    for (long i = 0; i < n; i++)
        cin >> arr[i];

    long long mini = 0, maxi = 0;
    long long sum = 0;
    for (long i = 0; i < n; i++)
    {
        double temp = arr[i] / (double)x;
        maxi += ceil(temp);
        if (arr[i] % x != 0)
        {
            sum += arr[i];
        }
        else
        {
            mini += (long)temp;
        }
    }
    double temp = sum / (double)x;

    mini += ceil(temp);
    cout << mini << " " << maxi << endl;
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