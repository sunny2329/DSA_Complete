#include <bits/stdc++.h>
using namespace std;

// frequency count
void frequencyCount(vector<int> &arr, int N, int P)
{
    // code here
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        int ind = i + 1;
        if (mp.find(ind) != mp.end())
        {
            arr[i] = mp[ind];
        }
        else
        {
            arr[i] = 0;
        }
    }
}

int main()
{
}