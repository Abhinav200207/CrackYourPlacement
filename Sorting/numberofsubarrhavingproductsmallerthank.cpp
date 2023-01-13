#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        long long product = 1;
        int count = 0;
        int i = 0, j = 0;

        if (k == 1)
        {
            return 0;
        }

        while (j < n)
        {
            product *= a[j];

            while (product >= k)
            {
                product /= a[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};