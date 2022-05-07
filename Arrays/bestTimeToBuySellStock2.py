class Solution(object):
    def maxProfit(self, v):
        n = len(v)
        dp = [0]*(n)
        dp[0] = 0
        for i in range(1,n):
            if (v[i-1] >= v[i]):
                dp[i] = dp[i - 1]
            else:
                dp[i] = dp[i - 1] + (v[i] - v[i - 1])
        return dp[n - 1]
        