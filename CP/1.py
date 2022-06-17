class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        d1 = {}
        d2 = {}
        for i in target:
            d1[i] = s.count(i)
            d2[i] = target.count(i)
        print(d1, d2)
        ans = 10000
        for i in d2:
            d2[i] = d1[i]/d2[i]
            ans = min(ans,d2[i])
        return ans