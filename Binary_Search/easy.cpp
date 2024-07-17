#include <bits/stdc++.h>
using namespace std;

// simple binary search
int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return -1;
}

// recursive binary search
int binarySearch(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}

// implement lower bound

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// implement upper bound
int upperBound(vector<int> arr, int x, int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// first occurence
int firstO(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}

// last occurence
int lastO(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}

// search in rotated sorted array

int searchRot(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}

// search in sorted array2

bool searchs(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return true;

        if ((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
        {
            l++;
            r--;
        }

        else if (nums[l] <= nums[mid])
        {

            if ((nums[l] <= target) && (nums[mid] > target))
                r = mid - 1;
            else
                l = mid + 1;
        }

        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

// find minimum in rotated sorted array

int findMin(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int m = (right + left) / 2;
        if (nums[m] < nums[right])
        {
            right = m;
        }
        else
        {
            left = m + 1;
        }
    }
    return nums[left];
}

// find Kth rotation

int findKthRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }

    return index;
}

// find the single element

int singleNonDuplicate(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid % 2 == 1)
        {
            mid--;
        }
        if (nums[mid] != nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 2;
        }
    }

    return nums[left];
}


//find the peak element

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int start = 0;
    int end = n - 2;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, n, x);
    // cout << ind << endl;
}