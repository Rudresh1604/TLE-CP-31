#include <bits/stdc++.h>
using namespace std;

long binaryToDecimal(string str)
{
    long dec_num = 0;
    long power = 0;
    int n = str.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            dec_num += (1 << power);
        }
        power++;
    }

    return dec_num;
}

void fun()
{
    long n;
    cin >> n;
    // logic
    /*
    1 & 1 = 1
    1 & 0 = 0
    *below is taken with respect to binary*
    after performing & operation the minimum possible value that we can get will
    be the position of elements where there will be 1

    So inside the array we will count frequency of each occurance of 1
    if fre of any element in bitarray is less then array size which means there must be 0
    at that position so the bit at that position will be 0
    then convert this binaryarray to num and that will be ans
    */
    vector<long> bitarray(64, 0);
    for (long i = 0; i < n; i++)
    {
        long p;
        cin >> p;
        string s = bitset<64>(p).to_string();
        for (int j = 0; j < 64; j++)
        {
            if (s[j] == '1')
            {
                bitarray[j]++;
            }
        }
    }
    string s = "";
    for (int i = 0; i < 64; i++)
    {
        if (bitarray[i] != n)
        {
            s += "0";
        }
        else
        {
            s += "1";
        }
    }

    cout << binaryToDecimal(s) << endl;
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