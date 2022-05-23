#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        if (x > 0)
        {
            // string s =
            string str = to_string(x);
            string rev = string(str.rbegin(), str.rend());
            long long int temp = stoll(rev);
            cout << temp << endl;
            return (temp > INT_MAX || temp < INT_MIN) ? 0 : temp;
        }
        else
        {
            x = -x;
            string str = to_string(x);
            string rev = string(str.rbegin(), str.rend());
            long long int temp = stoll(rev);
            cout << temp << endl;
            return (temp > INT_MAX || temp < INT_MIN) ? 0 : -temp;
        }
    }
};