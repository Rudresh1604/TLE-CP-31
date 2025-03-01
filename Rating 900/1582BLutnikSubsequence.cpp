#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to perform modular multiplication
long long modMult(long long a, long long b, long long mod)
{
    return (a * b) % mod;
}

// Function to perform modular exponentiation
long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = modMult(result, base, mod);
        }
        base = modMult(base, base, mod);
        exp /= 2;
    }
    return result;
}

// Function to perform modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long mod)
{
    return modPow(a, mod - 2, mod);
}

// Function to calculate nCk % MOD
long long comb(long long n, long long k, long long mod)
{
    if (k > n)
        return 0;
    long long num = 1;
    long long denom = 1;
    for (long long i = 1; i <= k; ++i)
    {
        num = modMult(num, n - i + 1, mod);
        denom = modMult(denom, i, mod);
    }
    return modMult(num, modInverse(denom, mod), mod);
}

void fun()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    long long onecnt = 0, zerocnt = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            onecnt++;
        if (arr[i] == 0)
            zerocnt++;
    }

    if (onecnt == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (zerocnt == 0)
    {
        cout << onecnt << endl;
        return;
    }

    long long ans = 0;
    for (long long i = 0; i <= zerocnt; i++)
    {
        long long cur = (comb(onecnt, 1, MOD) * comb(zerocnt, i, MOD)) % MOD;
        ans = (ans + cur) % MOD;
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
    return 0;
}
