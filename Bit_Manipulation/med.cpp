#include <bits/stdc++.h>
using namespace std;

// Minimum number for flips to reach the goal

int minBitFlips(int start, int goal)
{
    int c = (start ^ goal);
    int cnt = 0;
    while (c != 0)
    {
        if ((c & 1))
            cnt++;
        c = c / 2;
    }
    return cnt;
}

int main()
{
}