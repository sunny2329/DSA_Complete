#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
            cnt++;
        else
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
            cnt1++;
    }
    if (cnt1 > (n / 2))
        return el;
    return -1;
}


//dutch national flag algorithm
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
}