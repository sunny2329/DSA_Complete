#include <bits/stdc++.h>
using namespace std;

// find the next greater element
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res(nums1.size(), -1);
    stack<int> st;

    unordered_map<int, int> umap;

    for (int i = 0; i < nums2.size(); i++)
    {
        int element = nums2[i];
        while (!st.empty() && element > st.top())
        {
            umap[st.top()] = element;
            st.pop();
        }
        st.push(element);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        int el = nums1[i];
        if (umap.find(el) != umap.end())
        {
            int nge = umap[el];
            res[i] = nge;
        }
    }

    return res;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() <= nums[(i % n)])
            st.pop();
        if (i < n)
        {
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        st.push(nums[i % n]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
}