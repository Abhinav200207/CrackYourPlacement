class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        l = []
        for i in num:
            while (l and l[-1] > i and k):
                k = k - 1
                l.pop()
            l.append(i)
        l = l[:len(l)-k]
        res = "".join(l)
        return str(int(res)) if res else "0"