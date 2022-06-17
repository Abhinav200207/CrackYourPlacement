class Solution:
    def calculateTax(self, bt: list[list[int]], income: int) -> float:
        ans = 0
        if (bt[0][0] > income):
            ans = income*(bt[0][1]/100)
        else:
            for i in range(1, len(bt)):
                if (bt[i][0] > income):
                    ans += (income-bt[i-1][0])*(bt[0][1]/100)
                    break
                ans += (bt[i][0] - bt[i-1][0])*(bt[i][0]/100)
        return ans