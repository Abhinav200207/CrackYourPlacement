class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        if n == 2:
            return "11"
        s = "11"
        for i in range(3, n + 1):
            temp = ""
            cnt = 1
            s += "$"
            for i in range(1, len(s)):
                if s[i] == s[i-1]:
                    cnt += 1
                else:
                    temp += str(cnt)
                    temp += s[i - 1]
                    cnt = 1
            s = temp
        return s
