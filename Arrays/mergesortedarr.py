class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        i = m - 1
        j = n - 1
        t = m + n - 1
        while(i >= 0 and j >= 0):
            if (nums1[i] >= nums2[j]):
                nums1[t] = nums1[i]
                i -= 1
                t -= 1
            else:
                nums1[t] = nums2[j]
                j -= 1
                t -= 1
        while (j >= 0):
            nums1[t] = nums2[j]
            j -= 1
            t -= 1