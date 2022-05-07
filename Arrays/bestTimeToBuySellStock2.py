class Solution(object):
    def maxProfit(self, v):
        n = len(v)
        curr = 0
        prev = 0
        for i in range(1,n):
            if (v[i-1] >= v[i]):
                curr = prev
            else:
                curr = prev + (v[i] - v[i - 1])
                prev = curr
        return curr
        