class Solution:
    def countDistinct(self, nums: list[int], k: int, p: int) -> int:
        st = set()
        for i in range(len(nums)):
            tempL = []
            temp = k
            for j in range(i,len(nums)):
                if (temp <= 0):
                    break
                tempL.append(nums[j])
                st.add(tuple(tempL))
                if (nums[j] % p == 0):
                    temp -= 1
        return len(st)




# include <bits/stdc++.h>
# using namespace std;

# class Solution
# {
# public:
    # int countDistinct(vector<int> &nums, int k, int p)
    # {
        # unordered_set<string> set;
        # for (int i = 0; i < nums.size(); i++)
        # {
            # string st = "";
            # int temp = k;
            # for (int j = i; j < nums.size(); j++)
            # {
                # if (temp < 0)
                # {
                #     break;
                # }
                # st += to_string(nums[j]);
                # cout << st << " ";
                # set.insert(st);
                # if (nums[j] % p == 0)
                # {
                    # temp--;
                # }
            # }
        # }
        # return set.size();
    # }
# };