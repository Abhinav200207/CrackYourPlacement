#include <bits/stdc++.h>
using namespace std;

// 1. First evaluvate the index of Previous smaller elements and Next smaller elements.
// 2. Find the number of element b/w Previous smaller element and current elements by using difference of there indexes then find the number of element b/w Next smaller element and current element.
// 3. then use formula ans += (arr[i])(number of element b/w current and prev smaller ele + 1)(number of element b/w current and next smaller ele + 1)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<long long int> st;
        long long int n = arr.size();
        vector<long long int> next(n);
        next[n - 1] = n;
        st.push(n - 1);
        for (long long int i = n - 2; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if (!st.empty()){
                next[i] = st.top();
            }else{
                next[i] = n;
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        vector<long long int> prev(n);
        prev[0] = -1;
        st.push(0);
        for (long long int i = 1; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if (!st.empty()){
                prev[i] = st.top();
            }else{
                prev[i] = -1;
            }
            st.push(i);
        }
        long long int res = 0;
        long long int MOD = 1000000007;
        for (long long int i = 0; i < n; i++){
            res += arr[i]*(next[i] - i)*(i - prev[i]);
            res = res%MOD;
        }
        return int(res);
    }
};