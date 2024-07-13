#include <bits/stdc++.h>
using namespace std;

// selection sort
void selection_sort(int arr[], int n)
{
    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}


// bubble sort
void bubbleSort(int arr[], int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
}