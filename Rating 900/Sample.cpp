#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vector<long>> arr(n, vector<long>(m)); // Use vector<long> instead of vector<int>
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<long> rsum(n, 0), csum(m, 0);
    for (int i = 0; i < n; i++)
    {
        long sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        rsum[i] = sum;
    }

    for (long i = 0; i < m; i++)
    {
        long sum = 0;
        for (long j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }
        csum[i] = sum;
    }

    long r = 0, c = 0;
    long cnt = 0;
    while (cnt < n + m - 1)
    {
        if (s[cnt] == 'D')
        {
            arr[r][c] = -rsum[r];
            rsum[r] += arr[r][c];
            csum[c] += arr[r][c];
            r++;
        }
        else
        {
            arr[r][c] = -csum[c];
            rsum[r] += arr[r][c];
            csum[c] += arr[r][c];
            c++;
        }
        cnt++;
    }

    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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
    return 0;
}
