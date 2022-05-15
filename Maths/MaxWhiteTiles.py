class Solution:
    def maximumWhiteTiles(self, tiles: list[list[int]], k: int) -> int:
        sumnum = 0
        i = 0
        while (sumnum <= k):
            sumnum += (tiles[i][1] - tiles[i][0] + 1)
            i += 1
        if (tiles[i][0] <= k):
            sumnum += (k - tiles[i][0] + 1)
# obj = Solution()

# obj.maximumWhiteTiles([[1,5],[10,11],[12,18],[20,30],[31,32]],1)
