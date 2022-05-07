#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(auto i : nums){
            if(i==0) r++;
            else if(i==1) w++;
            else b++;
        }
        int i =0;
        while(r--){
            nums[i++]=0;
        }
        while(w--){
            nums[i++]=1;
        }
        while(b--){
            nums[i++]=2;
        }
    }
};