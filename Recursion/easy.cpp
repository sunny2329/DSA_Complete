#include <bits/stdc++.h>
using namespace std;

int atoint(string s, int num, bool isPositive)
{
    if (s.empty())
        return num;

    if (s[0] - '0' < 0 || s[0] - '0' > 9)
        return num;

    int nm = s[0] - '0';
    s.erase(s.begin());
    if (isPositive)
    {
        // if num is already greater than max / 10 then return max already since we
        // need to multiply num with 10 which will make it hard to compare with max since it
        // will get out of bounds
        if (num > INT_MAX / 10)
            return INT_MAX;
        // if num * 10 is in range of max int, we can compare (below expression is nm + num * 10 >= max
        // written like that to avoid out of range)
        if (nm >= INT_MAX - num * 10)
            return INT_MAX;
        // if adding nm to num * 10 is still range then return num * 10 + nm only.
        // (same approach for negative part)
        return atoint(s, num * 10 + nm, isPositive);
    }
    if (num < INT_MIN / 10)
        return INT_MIN;
    if (-nm <= INT_MIN - num * 10)
    {
        return INT_MIN;
    }
    return atoint(s, num * 10 - nm, isPositive);
}
// to convert given string to number only (and return 0 if invalid)
int myAtoi(string str)
{
    bool isPositive = true;
    // locked at 50 means no encounter with any sign
    int locked = 50;
    // converting given string into only numbers string
    while (str[0] - '0' < 0 || str[0] - '0' > 9)
    {
        // once we encounter any sign like + or -, locked gets locked to 100.
        // Now, if we encounter any space or anyother sign afterwards we change out lock to 0
        // which means it has been tampered. Therefore return 0.
        if (str[0] == '-' || str[0] == '+' || (locked == 100 && str[0] == ' '))
            if (locked == 50 || locked == 0)
                locked = 100;
            else
                locked = 0;
        if (locked == 0 || (str[0] != ' ' && str[0] != '+' && str[0] != '-' && (str[0] - '0' > 0 || str[0] - '0' <= 9)))
            return 0;
        if (str[0] == '-')
            isPositive = false;
        str.erase(str.begin());
    }
    return atoint(str, 0, isPositive);
}

int M = 1e9 + 7;
long long power(long long b, long long e, long long ans)
{
    if (e == 0)
        return ans;
    if (e & 1)
        return power(b, e - 1, (ans * b) % M);
    else
        return power((b * b) % M, e / 2, ans);
}
int countGoodNumbers(long long n)
{
    long long temp = power(20, n / 2, 1);
    return (n & 1) ? (temp * 5) % M : temp;
}

double bin(double x, long long k)
{
    if (k == 1)
        return x;
    double a = bin(x, k / 2);
    if (k & 1)
        return a * a * x;
    else
        return a * a;
}
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    long long k = long(abs(n));
    double ans = bin(x, k);
    if (n < 0)
        return 1 / ans;
    else
        return ans;
}

int main()
{
}