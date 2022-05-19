class Solution(object):
    def minMoves(self, nums):
        return sum(nums) - min(nums)*len(nums)