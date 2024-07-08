#include <bits/stdc++.h>
using namespace std;

// count the number of digits in N
int countDigits(int n)
{
    return (int)(log10(n) + 1);
}

// reverse the given integer
int reverseInt(int x)
{
    int ans = 0;
    while (x != 0)
    {
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    return ans;
}

vector<long long> lcmAndGcd(long long a, long long b)
{
    // code here
    vector<long long> ans;
    long long i = a, j = b;
    long long int gcd = 0;
    long long int lcm = 0;
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        gcd = b;
    else
        gcd = a;
    lcm = abs(i * j) / gcd;
    ans.push_back(lcm);
    ans.push_back(gcd);
    return ans;
}

int main()
{
}