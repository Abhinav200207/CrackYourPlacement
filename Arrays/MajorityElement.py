class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        ele = nums[0]
        cnt = 1
        for i in nums:
            if cnt == 0:
                ele = i
                cnt = 1
            if ele == i:
                cnt += 1
            elif ele != i:
                cnt -= 1
        return cnt