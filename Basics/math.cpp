#include <bits/stdc++.h>
using namespace std;

// count the number of digits in N
int countDigits(int n)
{
    return (int)(log10(n) + 1);
}

// reverse the given integer
int reverseInt(int x)
{
    int ans = 0;
    while (x != 0)
    {
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    return ans;
}

// gcd and lcm
vector<long long> lcmAndGcd(long long a, long long b)
{
    // code here
    vector<long long> ans;
    long long i = a, j = b;
    long long int gcd = 0;
    long long int lcm = 0;
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        gcd = b;
    else
        gcd = a;
    lcm = abs(i * j) / gcd;
    ans.push_back(lcm);
    ans.push_back(gcd);
    return ans;
}

bool isArmstrong(int num)
{
    // Calculate the number of
    // digits in the given number
    int k = to_string(num).length();
    // Initialize the sum of digits
    // raised to the power of k to 0
    int sum = 0;
    // Copy the value of the input
    // number to a temporary variable n
    int n = num;
    // Iterate through each
    // digit of the number
    while (n > 0)
    {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Add the digit raised to
        // the power of k to the sum
        sum += pow(ld, k);
        // Remove the last digit
        // from the number
        n = n / 10;
    }
    // Check if the sum of digits raised to
    // the power of k equals the original number
    return sum == num ? true : false;
}

// sum of all divisors from 1 to n
int sumOfdDivisors(int i)
{
    int sum = 0;
    for(int j = 1;j*j<=i;++j){
        if(i%j == 0){
            sum += j ;
            if(j!=i/j){
                sum += i / j;
            }
        }
    }
}

long long sumofDivisors(int N){
    long long totalSum = 0;
    for(int i = 1; i<=N;++i){
        totalSum += sumOfdDivisors(i);
    }
    return totalSum;
}

int main()
{
}