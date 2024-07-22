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

int check(vector<int> &piles, int h, int mid)
{
    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += (piles[i] / mid);
        if (piles[i] % mid != 0)
            ans++;
    }
    return ans <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    sort(piles.begin(), piles.end());
    int n = piles.size();
    int low = 1;
    int high = piles[n - 1];

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check(piles, h, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
}