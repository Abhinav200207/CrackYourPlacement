class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        combHelper(num, 0, num.size(), target, vector<int>(), result);
        return result;
    }
    
    void combHelper(vector<int>& a, int start, int n, int target, 
    vector<int> cur_vec, vector<vector<int> >& result) {
        
        if (target == 0) {
            result.push_back(cur_vec);
            return;
        }
        int i = start;
        while(i < n  && target-a[i] >= 0) {
            // NOTE : this condition helps neglecting making identical sets
            //  this is the catch of this question
            if (i == start || a[i] != a[i-1]) {
                cur_vec.push_back(a[i]);
                combHelper(a, i+1, n, target-a[i], cur_vec, result);
                cur_vec.pop_back();
            }
            i++;
        }
    }
};