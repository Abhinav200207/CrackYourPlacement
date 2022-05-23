// Max value Equations

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> points, int k)
    {
        int ans = INT_MIN;
        for (int i = 0; i < points.size(); i++)
        {
            int temp = k;
            int j = i + 1;
            cout << points[i][0] << " : ";
            while (j < points.size() && abs(points[i][0] - points[j][0]) <= temp)
            {   
                ans = max((points[i][1] + points[j][1] + abs(points[i][0] - points[j][0])), ans);
                cout << points[j][0] << " ";
                j++;
            }
            cout << endl;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    obj.findMaxValueOfEquation({{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 1}},~ 4);
}