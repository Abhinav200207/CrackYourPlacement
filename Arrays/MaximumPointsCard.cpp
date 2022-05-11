#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> cardPoints, int k)
    {
        int n = cardPoints.size();
        int slidLength = n - k;
        int left = 0;
        int right = slidLength - 1;
        int ans = 0;
        for (int i = right + 1; i < n; i++)
        {
            ans += cardPoints[i];
        }
        for (int i = 1; i < k; i++)
        {
            int temp = ans - cardPoints[right++] + cardPoints[left++];
            ans = max(ans, temp);
            cout << i << " " << ans << endl;
        }
        int temp = 0;
        for (int i = 0; i < left; i++)
        {
            temp += cardPoints[i];
        }
        return max(temp,ans);
    }
};

int main()
{
    Solution obj;
    cout << obj.maxScore({11,49,100,20,86,29,72}, 4);
}
// [11,49,100,20,86,29,72] k = 4
//             |     |

// 20 + 86 + 29 + 72 = 307


// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int sm = 0;
//         int lft = k-1, rht = n-1;
//         for(int i = 0; i < k; i++)
//         {
//             sm += cardPoints[i];
//         }
//         int mx = sm;
//         while(k--)
//         {
//             sm =sm - cardPoints[lft--] + cardPoints[rht--];
//             mx = max(mx,sm);
//         }
//         return mx;
//     }
// };