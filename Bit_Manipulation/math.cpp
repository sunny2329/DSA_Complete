#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n)
{
    // Code here.
    vector<int> sqq;
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        if (n % i == 0)
        {
            sqq.push_back(i);
            if (i != n / i)
            {
                sqq.push_back(n / i);
            }
        }
    }
    sort(sqq.begin(), sqq.end());
    for (int i = 0; i < sqq.size(); i++)
    {
        cout << sqq[i] << " ";
    }
}

int countPrimes(int n)
{
    vector<int> prime(n, 1);
    for (int i = 2; i * i < n; ++i)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i < n; ++i)
    {
        if (prime[i] == 1)
            ans++;
    }

    return ans;
}

int main()
{
}