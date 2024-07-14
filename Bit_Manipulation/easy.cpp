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
    long long int sets = num | (1 << k);
    long long int clears = num & ~(1 << k);
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

// set the right most bit
int setBit(int n)
{
    // Write Your Code here
    int m = n;
    int cnt = 0;
    while (m != 0)
    {
        if ((m & 1) == 0)
            break;
        cnt++;
        m = m >> 1;
    }
    return n | (1 << cnt);
}

// swap two number with xor
pair<int, int> get(int a, int b)
{
    // complete the function here
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    pair<int, int> p1;
    p1.first = a;
    p1.second = b;
    return p1;
}

int main()
{
}