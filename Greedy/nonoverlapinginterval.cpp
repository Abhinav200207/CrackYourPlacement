#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2){ return i1[1] < i2[1]; };
        sort(in.begin(),in.end(),comp);
        stack<vector<int>> st;
        st.push(in[0]);
        int ans = 0;
        for (int i = 1; i < in.size(); i++){
            if (st.top()[1] > in[i][0]){
                ans++;
            }else{
                st.push(in[i]);
            }
        }
        return ans;
    }
};