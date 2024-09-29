#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    if (prime[n])
    {
        return 1;
    }
    return 0;
}
void bruteFun()
{
    long long n;
    cin >> n;

    vector<long> factor;
    for (long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            factor.push_back(i);
            if (i != n / i)
            {
                factor.push_back(n / i);
            }
        }
    }

    sort(factor.begin(), factor.end());

    long ans = 0, cur_cnt = 0;
    for (int i = 1; i < factor.size(); i++)
    {
        if (factor[i] - factor[i - 1] <= 1)
        {
            cur_cnt++;
            ans = max(ans, cur_cnt);
        }
        else
        {
            cur_cnt = 0;
        }
    }
    cout << ans + 1 << endl;
}

void fun()
{
    long long n;
    cin >> n;

    // if n is prime then it can be only divisible by 1 and itself so ans is 1
    //  if n is odd no ex 9 then ans = 1 becoz
    //  even odd even as there are no consecutive so ans is always 1
    // if n is even then then lenght will be from 1 to any no such that
    // it will not satisfy the condition
    // ex 120 => 1,2,3,4,5,6,(7) => here max range of divisors is 6

    long ans = 0;
    for (long i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans++;
        }
        else
        {
            break;
        }
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