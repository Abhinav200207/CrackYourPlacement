class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        st = 0
        ans = 0
        for r in range(len(s)):
            count[s[r]] = count.get(s[r],0) + 1
            if (r - st + 1) - max(count.values()) > k:
                count[s[st]] -= 1
                st += 1
            ans = max(ans,(r - st + 1))
        return ans