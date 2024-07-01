#include <bits/stdc++.h>
using namespace std;


//1. Print 1 to N without loop 
void printNos(int N, int cnt = 1){
    if(N<=0) return;
    printNos(N-1);
    cout << N << " ";
}




int main()
{
}