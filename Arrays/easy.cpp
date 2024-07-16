#include <bits/stdc++.h>
using namespace std;

// print the second largest element
int print2largest(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(arr[i], maxi);
    }
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != maxi)
        {
            ans = max(arr[i], ans);
        }
    }
    return ans;
}

// remove duplicates
int removeDuplicates(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        else
            arr[i - count] = arr[i];
    }
    return arr.size() - count;
}

// rotate array
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// move zeros
void moveZeros(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
            nums[i++] = nums[j];
    }
    while (i < nums.size())
        nums[i++] = 0;
}

// Union of two sorted arrays

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements
    int i = 0, j = 0;  // pointers
    vector<int> Union; // Uninon vector
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

// find the missing number
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int real = (n * (n + 1)) / 2;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return real - sum;
}

// find the maximum consecutive ones
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] == 1)
            count++;
        else
        {
            ans = max(count, ans);
            count = 0;
        }
    }
    ans = max(ans, count);
    return ans;
}

// find the single element in the array
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

// find the length of the longest subarray with sum k (positive)
int maxLenSub(vector<int> &nums, int k)
{
    int m = k;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum += nums[l];
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
            maxLen = i + 1;

        if (um.find(sum) == um.end())
            um[sum] = i;

        if (um.find(sum - K) != um.end())
        {
            if (maxLen < (i - um[sum - K]))
                maxLen = i - um[sum - K];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {12, 14, 16, 18, 20};
    int k = 30;
    cout << "Second largest element: " << maxLenSub(nums, k) << endl;
}