#include <bits/stdc++.h>
using namespace std;

void fun()
{
    long a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    long pos1 = a1 + a2, pos2 = a4 - a2;
    long sum = 0;
    long cnt = 0;
    if (pos1 + a2 == a4)
        cnt++;
    if (a1 + a2 == pos1)
        cnt++;
    if (pos1 + a4 == a5)
        cnt++;
    sum = max(sum, cnt);
    cnt = 0;
    if (pos2 + a2 == a4)
        cnt++;
    if (a1 + a2 == pos2)
        cnt++;
    if (pos2 + a4 == a5)
        cnt++;
    sum = max(sum, cnt);
    cnt = 0;
    if (a2 == a4)
        cnt++;
    if (a1 + a2 == 0)
        cnt++;
    if (a4 == a5)
        cnt++;
    sum = max(sum, cnt);
    cout << sum << endl;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
