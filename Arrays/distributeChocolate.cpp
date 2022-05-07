#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        long long prev = INT_MAX;
        sort(a.begin(), a.end());
        for (long long i = 0; i <= n - m; i++)
        {
            if (a[i + m - 1] - a[i] < prev)
            {
                prev = a[i + m - 1] - a[i];
            }
        }
        return prev;
    }
};

int main()
{
    Solution solve;
    cout << solve.findMinDiff({3, 4, 1, 9, 56, 7, 9, 12}, 8, 5);
}

// {3, 4, 1, 9, 56, 7, 9, 12} 
// {1, 3, 4, 7, 9, 9, 12, 56}