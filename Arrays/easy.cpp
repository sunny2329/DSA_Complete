#include <bits/stdc++.h>
using namespace std;


int print2largest(vector<int> &arr){
    int maxi = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        maxi = max(arr[i],maxi);
    }
    int ans = -1;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] != maxi){
            ans = max(arr[i],ans);
        }
    }
    return ans;
}


int main()
{
}