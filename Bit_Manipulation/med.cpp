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

// power set
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int size = 1 << n;
    vector<vector<int>> ans(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                ans[i].push_back(nums[j]);
            }
        }
    }
    return ans;
}

int main()
{
}