#include <bits/stdc++.h>
using namespace std;


//1. Print 1 to N without loop 
void printNos(int N, int cnt = 1){
    if(N<=0) return;
    printNos(N-1);
    cout << N << " ";
}

//2. Print your name N time without name
void printName(int N){
    if(N<=0) return;
    cout << "Sobhit" << " ";
    printName(N-1);
}

//3. Sum of no
int func(int n){
    if(n==0) return 0;
    return n + func(n-1);
}

//4. Factorial 
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

//5. reverse an array using recursion
void reverses(int arr[],int start, int end){
    if(start>=end) return;
    swap(arr[start++],arr[end--]);
    reverses(arr,start,end);
}





int main()
{
    // printName(5);
    // int arr[6] = {1,2,3,4,5,6};
    // reverses(arr,0,5);
    // for(int i=0; i<6; i++)
    //     cout << arr[i] << " ";
    return 0;
}