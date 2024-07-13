#include <bits/stdc++.h>
using namespace std;

// 1.Get ith bit 2. Set the ith bit 3. Clear the ith bit;
void bitManipulation(int num, int i)
{
    int j = 1;
    int m = num;
    while (j < i)
    {
        m = m >> 1;
        j++;
    }
    int get = m & 1;
    cout << get;
    long long int k = i - 1;
    long long int sets = nums | (1 << k);
    long long int clears = nums & ~(1 << k);
}

// check the kth bit;
bool checkKthBit(int n, int k)
{
    return n & (1 << k);
}

// check for odd or even
string oddEven(int n)
{
    if (n & 1)
        return "odd";
    else
        return "even";
}

// check isPowerOfTwo
bool isPowerOfTwo(int n)
{
    if (n >= 1 && (n & (n - 1)) == 0)
        return true;
    return false;
}

// count the set bits
int countSetBits(int n)
{
    // Your logic here
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            if ((x & 1) == 1)
                cnt++;
            x /= 2;
        }
    }
    return cnt;
}

int main()
{
}