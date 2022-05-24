class Solution:
    def canJump(self, nums: list[int]) -> bool:
        prev = nums[0]
        for i in range(1,len(nums)):
            if (prev == 0):
                return False
            if (nums[i] > prev - 1):
                prev = nums[i]
            if (nums[i] <= prev - 1):
                nums[i] = prev - 1
                prev = nums[i]
        return True