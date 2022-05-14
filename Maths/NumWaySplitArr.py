class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        totsum = sum(nums)
        count = 0
        left = 0
        for i in range(0,len(nums) - 1):
            left += nums[i]
            right = totsum - left
            if (left >= right):
                count += 1
        return count