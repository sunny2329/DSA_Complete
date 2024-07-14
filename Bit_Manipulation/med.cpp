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

// find XOR between range of L to R
int func(int r)
{
    if (r % 4 == 1)
        return 1;
    if (r % 4 == 2)
        return r + 1;
    if (r % 4 == 3)
        return 0;
    if (r % 4 == 0)
        return r;
}
int findXOR(int l, int r)
{
    // complete the function here
    return func(l - 1) ^ func(r);
}

// find the elements appearing odd number of times
vector<long long int> twoOddNum(long long int Arr[], long long int N)
{

    long long int xor2 = Arr[0]; /* Will hold XOR of two odd occurring elements */
    long long int set_bit_no;    /* Will have only single set bit of xor2 */
    long long int i, x = 0, y = 0;

    /* Get the xor of all elements in Arr[]. The xor will basically
        be xor of two odd occurring elements */
    for (i = 1; i < N; i++)
        xor2 = xor2 ^ Arr[i];

    /* Get one set bit in the xor2. We get rightmost set bit
        in the following line as it is easy to get */
    set_bit_no = xor2 & ~(xor2 - 1);

    /* Now divide elements in two sets:
        1) The elements having the corresponding bit as 1.
        2) The elements having the corresponding bit as 0. */
    for (i = 0; i < N; i++)
    {
        /* XOR of first set is finally going to hold one odd
        occurring number x */
        if (Arr[i] & set_bit_no)
            x = x ^ Arr[i];

        /* XOR of second set is finally going to hold the other
        odd occurring number y */
        else
            y = y ^ Arr[i];
    }

    // Creating a vector to store the two odd occurring numbers.
    vector<long long int> v;
    v.push_back(max(x, y)); // Inserting maximum odd occurring number into vector
    v.push_back(min(x, y)); // Inserting minimum odd occurring number into vector
    return v;
}

int main()
{
}