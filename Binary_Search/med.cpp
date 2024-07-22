#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x)
{
    // Your code goes here
    int s = 1, e = x;
    while (s <= e)
    {
        long long mid = (e + s) / 2;
        long long val = mid * mid;
        if (val <= (long long)(x))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

int main()
{
}